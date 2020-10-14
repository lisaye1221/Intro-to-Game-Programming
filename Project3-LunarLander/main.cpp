#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif
#include<vector>
#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Entity.h"

#define PLATFORM_COUNT 2
#define WALL_COUNT 32

struct GameState {
    Entity* player;
    Entity* wall;
    Entity* platform;
};

GameState state;

SDL_Window* displayWindow;
bool gameIsRunning = true;
bool gameLost = false;
bool gameWon = false;

ShaderProgram program;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;
GLuint fontTextureID;
float pauseTicks = 0;
float lastTicks = 0;

// function prototypes
void DrawText(ShaderProgram* program, GLuint fontTextureID, const std::string& text,
    float size, float spacing, glm::vec3 position);
void placeWallTile();
void textDisplay();
void reset();

GLuint LoadTexture(const char* filePath) {
    int w, h, n;
    unsigned char* image = stbi_load(filePath, &w, &h, &n, STBI_rgb_alpha);

    if (image == NULL) {
        std::cout << "Unable to load image. Make sure the path is correct\n";
        assert(false);
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    stbi_image_free(image);
    return textureID;
}


void Initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    displayWindow = SDL_CreateWindow("Lunar Lander", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 640, 480);

    program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");

    viewMatrix = glm::mat4(1.0f);
    modelMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-6.0f, 6.0f, -4.0f, 4.0f, -1.0f, 1.0f);

    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);

    glUseProgram(program.programID);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    fontTextureID = LoadTexture("font1.png");
    // Initialize Game Objects

    // Initialize Player
    state.player = new Entity();
    state.player->position = glm::vec3(-0.5, 3.5f, 0);
    state.player->movement = glm::vec3(0);
    state.player->acceleration = glm::vec3(0, -0.5f, 0);
    state.player->textureID = LoadTexture("rocket.png");

    state.player->enginePower = 0.05f;

    state.platform = new Entity[PLATFORM_COUNT];
    GLuint platformTextureID = LoadTexture("platform.png");
    state.platform[0].textureID = platformTextureID;
    state.platform[0].position = glm::vec3(3.5f, -3.5, 0);

    state.platform[1].textureID = platformTextureID;
    state.platform[1].position = glm::vec3(4.5f, -3.5, 0);

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        state.platform[i].Update(0, NULL, 0);
    }

    state.wall = new Entity[WALL_COUNT];
    GLuint wallTextureID = LoadTexture("wall.png");
    for (int i = 0; i < WALL_COUNT; i++) {
        state.wall[i].textureID = wallTextureID;
    }

    placeWallTile();

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        state.platform[i].Update(0, NULL, 0);
    }
    for (int i = 0; i < WALL_COUNT; i++) {
        state.wall[i].Update(0, NULL, 0);
    }


}

void ProcessInput() {

    state.player->movement = glm::vec3(0);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            gameIsRunning = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_SPACE:
                if (gameLost) {
                    reset();
                    pauseTicks = (float)SDL_GetTicks() / 1000.0f - lastTicks;
                }
                break;
            }
            break; // SDL_KEYDOWN
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_LEFT]) {
        state.player->acceleration.x -= state.player->enginePower;
    }
    else if (keys[SDL_SCANCODE_RIGHT]) {
        state.player->acceleration.x += state.player->enginePower;
    }
    if (glm::length(state.player->movement) > 1.0f) {
        state.player->movement = glm::normalize(state.player->movement);
    }

}

#define FIXED_TIMESTEP 0.0166666f
float accumulator = 0.0f;
void Update() {
    float ticks = (float)SDL_GetTicks() / 1000.0f - pauseTicks;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;
    deltaTime += accumulator;
    if (deltaTime < FIXED_TIMESTEP) {
        accumulator = deltaTime;
        return;
    }
    while (deltaTime >= FIXED_TIMESTEP) {
        // Update. Notice it's FIXED_TIMESTEP. Not deltaTime
        state.player->Update(FIXED_TIMESTEP, state.platform, PLATFORM_COUNT);
        deltaTime -= FIXED_TIMESTEP;
    }
    accumulator = deltaTime;

    // check game logic
    if (state.player->lastCollided == state.wall) {
        gameLost = true;
    }
    else if (state.player->lastCollided == state.platform) {
       gameWon = true;
    }
}


void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        state.platform[i].Render(&program);
    }

    for (int i = 0; i < WALL_COUNT; i++) {
        state.wall[i].Render(&program);
    }

    state.player->Render(&program);

    textDisplay();

    SDL_GL_SwapWindow(displayWindow);
}


void Shutdown() {
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    Initialize();

    while (gameIsRunning) {
        ProcessInput();
        if (!gameWon && !gameLost) {
            Update();
        }
        Render();
    }

    Shutdown();
    return 0;
}


void placeWallTile() {
    for (int i = 0; i < 16; i++) {
        if (i < 8) {
            state.wall[i].position = glm::vec3(-5.5f, -4.5f + (i + 1), 0);
        }
        else {
            state.wall[i].position = glm::vec3(5.5f, -4.5f + (i - 7), 0);
        }
    }
    for (int i = 16; i < 24; i++) {
        state.wall[i].position = glm::vec3(-4.5f + (i - 16), -3.5f, 0);
    }
    state.wall[24].position = glm::vec3(2.5f, -0.5f, 0);
    state.wall[25].position = glm::vec3(4.5f, -0.5f, 0);
    state.wall[26].position = glm::vec3(3.5f, -0.5f, 0);

    state.wall[27].position = glm::vec3(-4.5f, 0.5f, 0);
    state.wall[28].position = glm::vec3(-3.5f, 0.5f, 0);
    state.wall[29].position = glm::vec3(-2.5f, 0.5f, 0);

    state.wall[30].position = glm::vec3(0.0f, 1.5f, 0);
    state.wall[31].position = glm::vec3(1.0f, 2.5f, 0);
}

void DrawText(ShaderProgram* program, GLuint fontTextureID, const std::string& text,
    float size, float spacing, glm::vec3 position)
{
    float width = 1.0f / 16.0f;
    float height = 1.0f / 16.0f;
    std::vector<float> vertices;
    std::vector<float> texCoords;
    for (int i = 0; i < text.size(); i++) {
        int index = (int)text[i];
        float offset = (size + spacing) * i;
        float u = (float)(index % 16) / 16.0f;
        float v = (float)(index / 16) / 16.0f;
        vertices.insert(vertices.end(), {
            offset + (-0.5f * size), 0.5f * size,
            offset + (-0.5f * size), -0.5f * size,
            offset + (0.5f * size), 0.5f * size,
            offset + (0.5f * size), -0.5f * size,
            offset + (0.5f * size), 0.5f * size,
            offset + (-0.5f * size), -0.5f * size,
            });
        texCoords.insert(texCoords.end(), {
            u, v,
            u, v + height,
            u + width, v,
            u + width, v + height,
            u + width, v,
            u, v + height,
            });
    } // end of for loop
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    program->SetModelMatrix(modelMatrix);
    glUseProgram(program->programID);
    glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, vertices.data());
    glEnableVertexAttribArray(program->positionAttribute);
    glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords.data());
    glEnableVertexAttribArray(program->texCoordAttribute);
    glBindTexture(GL_TEXTURE_2D, fontTextureID);
    glDrawArrays(GL_TRIANGLES, 0, (int)(text.size() * 6));
    glDisableVertexAttribArray(program->positionAttribute);
    glDisableVertexAttribArray(program->texCoordAttribute);

}

void textDisplay() {
    if (gameWon) {
        DrawText(&program, fontTextureID, "Mission Successful", 0.7, -0.35, glm::vec3(-2.5, 0.5, 0));
        
    }
    else if (gameLost) {
        DrawText(&program, fontTextureID, "Mission Failed", 0.7, -0.35, glm::vec3(-2.5, 0.5, 0));
        DrawText(&program, fontTextureID, "Press Space Bar to Try Again", 0.5, -0.3, glm::vec3(-2.8, -0.5, 0));
    }
}

void reset() {
    gameLost = false;
    gameWon = false;
    state.player->position = glm::vec3(-0.5, 3.5f, 0);
    state.player->acceleration = glm::vec3(0, -0.5f, 0);
    state.player->movement = glm::vec3(0);
    state.player->lastCollided = nullptr;
}