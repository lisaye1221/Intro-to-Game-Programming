#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Entity.h"
#include "Player.h"
#include "NPC.h"

#define PLATFORM_COUNT 11
#define PLATFORML1_COUNT 11
#define PLATFORML2_COUNT 11
#define PLATFORML3_COUNT 5
#define LADDER_COUNT 3
#define ENEMY_COUNT 1

using namespace std;

struct GameState {
    Player* player;
    vector<Entity*> platform;
    vector<Entity*> platformL1;
    vector<Entity*> platformL2;
    vector<Entity*> platformL3;
    vector<Entity*> ladder;
    vector<NPC*> enemies;
    vector<Entity*> allEntities;
};

GameState state;

SDL_Window* displayWindow;
bool gameIsRunning = true;
bool gameWon = false;
bool gameLost = false;
float timeLeft = 100;

ShaderProgram program;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;
GLuint fontTextureID;

Mix_Music* music;
Mix_Chunk* pop_sfx;
Mix_Chunk* jump_sfx;
Mix_Chunk* win;
Mix_Chunk* lose;


void makePlatform();
void makeLadder();
void displayText();
void DrawText(ShaderProgram* program, GLuint fontTextureID, const std::string& text,
    float size, float spacing, glm::vec3 position);

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
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    displayWindow = SDL_CreateWindow("Bunnies", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 500, 600);

    program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");

    // Start Audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    music = Mix_LoadMUS("assets/banana_tree.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    // Check load
    if (music == NULL) {
        cout << "Fail to load music. " << Mix_GetError() << std::endl;
    }
    Mix_PlayMusic(music, -1);


    pop_sfx = Mix_LoadWAV("assets/contact.wav");
    jump_sfx = Mix_LoadWAV("assets/jump.wav");
    win = Mix_LoadWAV("assets/win.wav");
    lose = Mix_LoadWAV("assets/lose.wav");
    Mix_VolumeChunk(pop_sfx, MIX_MAX_VOLUME / 3);
    Mix_VolumeChunk(jump_sfx, MIX_MAX_VOLUME / 3);
    Mix_VolumeChunk(win, MIX_MAX_VOLUME / 3);
    Mix_VolumeChunk(lose, MIX_MAX_VOLUME / 3);

    viewMatrix = glm::mat4(1.0f);
    modelMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -6.0f, 6.0f, -1.0f, 1.0f);

    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);

    glUseProgram(program.programID);
  
    glClearColor(165.0f/255.0f, 213.0f/255.0f, 217.0f/255.0f, 1.0f);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    fontTextureID = LoadTexture("assets/font1.png");

    // Initialize Game Objects

    // Initialize Player
    GLuint textID = LoadTexture("assets/george_0.png");
    glm::vec3 initialPos = glm::vec3(-4, -4, 0);
    float speed = 1.5f;

    state.player = new Player(textID, initialPos, speed);
    state.allEntities.push_back(state.player);

    state.player->setSize(0.6f,0.8f);

    state.player->animRight = new int[4]{ 3, 7, 11, 15 };
    state.player->animLeft = new int[4]{ 1, 5, 9, 13 };
    state.player->animUp = new int[4]{ 2, 6, 10, 14 };
    state.player->animDown = new int[4]{ 0, 4, 8, 12 };

    state.player->animIndices = state.player->animRight;
    state.player->animFrames = 4;
    state.player->animIndex = 0;
    state.player->animTime = 0;
    state.player->animCols = 4;
    state.player->animRows = 4;

    makePlatform();
    makeLadder();

    textID = LoadTexture("assets/bunny.png");
    initialPos = glm::vec3(3, -4.55, 0);
    speed = 0.8f;
    NPC* newNPC = new NPC(textID, initialPos, speed, RUNNER, IDLE);
    newNPC->setFacing(LEFT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    initialPos = glm::vec3(2, -1.55, 0);
    speed = state.player->getSpeed();
    newNPC = new NPC(textID, initialPos, speed, COPIER, IDLE);
    newNPC->setFacing(LEFT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    initialPos = glm::vec3(-1.5, 1.55, 0);
    speed = 5.0;
    newNPC = new NPC(textID, initialPos, speed, SLEEPER, IDLE);
    newNPC->setFacing(LEFT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    initialPos = glm::vec3(1.5, 1.55, 0);
    speed = 5.0;
    newNPC = new NPC(textID, initialPos, speed, SLEEPER, IDLE);
    newNPC->setFacing(RIGHT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    for (NPC* npc : state.enemies) {
        npc->setSize(1.0f, 0.8);

        npc->animLeft = new int[5]{ 0, 1, 2, 3, 4 };
        npc->animRight = new int[5]{ 5 , 6 , 7, 8, 9};
        
        npc->animIndices = npc->getFacing() == LEFT? npc->animLeft : npc->animRight;
        npc->animFrames = 5;
        npc->animIndex = 0;
        npc->animTime = 0;
        npc->animCols = 10;
        npc->animRows = 1;

    }


}

void ProcessInput() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
            case SDL_WINDOWEVENT_CLOSE:
                gameIsRunning = false;
                break;
            default:
                state.player->ProcessPlayerInput(event);
        }
    }
    //state.player->ProcessPlayerInput();

}

#define FIXED_TIMESTEP 0.0166666f
float lastTicks = 0;
float accumulator = 0.0f;
void Update() {
    float ticks = (float)SDL_GetTicks() / 1000.0f;
    float deltaTime = ticks - lastTicks;
    if (!gameWon && !gameLost) { timeLeft -= deltaTime; }
    else { timeLeft = 0; }
    lastTicks = ticks;
    deltaTime += accumulator;
    if (deltaTime < FIXED_TIMESTEP) {
        accumulator = deltaTime;
        return;
    }
    while (deltaTime >= FIXED_TIMESTEP) {
        if (!gameWon && !gameLost) {
            // Update. Notice it's FIXED_TIMESTEP. Not deltaTime
            state.player->Update(FIXED_TIMESTEP, state.allEntities);

            for (NPC* npc : state.enemies) {
                npc->Update(FIXED_TIMESTEP, state.player, state.allEntities);
            }
        }
        deltaTime -= FIXED_TIMESTEP;
    }
    accumulator = deltaTime;

    if (state.player->getBunniesCaptured() == 4 && !gameLost && !gameWon) { 
        gameWon = true; 
        Mix_PlayChannel(-1, win, 0);
        // Stop the music!
        Mix_HaltMusic();
    }
    if (timeLeft <= 0 && !gameLost && !gameWon) { 
        gameLost = true; 
        Mix_PlayChannel(-1, lose, 0);
        // Stop the music!
        Mix_HaltMusic();
    }

    if (state.player->justCapturedBunny) { 
        Mix_PlayChannel(-1, pop_sfx, 0); 
        state.player->justCapturedBunny = false;
    }
    if (state.player->justJumped) {
        Mix_PlayChannel(-1, jump_sfx, 0);
        state.player->justJumped = false;
    }

}


void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        state.platform[i]->Render(&program);
    }
    for (int i = 0; i < PLATFORML1_COUNT; i++) {
        state.platformL1[i]->Render(&program);
    }
    for (int i = 0; i < PLATFORML2_COUNT; i++) {
        state.platformL2[i]->Render(&program);
    }
    for (int i = 0; i < PLATFORML3_COUNT; i++) {
        state.platformL3[i]->Render(&program);
    }

    for (Entity* entity : state.ladder) {
        entity -> Render(&program);
    }
    for (NPC* npc : state.enemies) {
        npc->Render(&program);
   }

    state.player->Render(&program);

    displayText();

    SDL_GL_SwapWindow(displayWindow);
}


void Shutdown() {
    // free memory of all entities
    for (Entity* entity : state.allEntities) {
        delete entity;
    }

    // free memory of music
    Mix_FreeChunk(pop_sfx);
    Mix_FreeChunk(jump_sfx);
    Mix_FreeChunk(win);
    Mix_FreeChunk(lose);
    Mix_FreeMusic(music);

    SDL_Quit();
}

int main(int argc, char* argv[]) {
    Initialize();

    while (gameIsRunning) {
        ProcessInput();
        Update();
        Render();
    }

    Shutdown();
    return 0;
}

void displayText() {
    DrawText(&program, fontTextureID, "Time Left: " + to_string(int(timeLeft)), 0.45, -0.23, glm::vec3(-4.5, 5.5, 0));
    DrawText(&program, fontTextureID, "Bunnies:" + to_string(state.player->getBunniesCaptured()) + "/4", 0.45, -0.23, glm::vec3(2.5, 5.5, 0));
    DrawText(&program, fontTextureID, "Arrow Key: Move     Space Bar: Jump" , 0.45, -0.23, glm::vec3(-3.5, -5.7, 0));
    if (gameWon) {
        DrawText(&program, fontTextureID, "Task Completed", 0.7, -0.35, glm::vec3(-2.5, 0.5, 0));
        DrawText(&program, fontTextureID, "Thanks for bringing the bunnies back!", 0.55, -0.33, glm::vec3(-3.8, -0.2, 0));
    }
    else if (gameLost) {
        DrawText(&program, fontTextureID, "Task Failed", 0.7, -0.35, glm::vec3(-2, 0.5, 0));
    }
}


void makePlatform() {
    GLuint textID = LoadTexture("assets/platform.png");
    glm::vec3 initialPos = glm::vec3(0);

    for (int i = 0; i < PLATFORM_COUNT; i++) {
        Entity* newEntity = new Entity(EntityType::PLATFORM, textID, initialPos, 0);
        newEntity->setPosition(glm::vec3(-5 + i, -5.5f, 0));
        state.platform.push_back(newEntity);
        state.allEntities.push_back(newEntity);
        newEntity->Update(0, {});
    }

    for (int i = 0; i < PLATFORML1_COUNT; i++) {

        Entity* newEntity = new Entity(EntityType::PLATFORM, textID, initialPos, 0);
        newEntity->setPosition(glm::vec3(-5 + i, -2.52f, 0));
        state.platformL1.push_back(newEntity);
        state.allEntities.push_back(newEntity);
        if (-5 + i == -1) { newEntity->isActive = false; }
        newEntity->Update(0, {});
    }

    for (int i = 0; i < PLATFORML2_COUNT; i++) {
        Entity* newEntity = new Entity(EntityType::PLATFORM, textID, initialPos, 0);
        newEntity->setPosition(glm::vec3(-5 + i, 0.48f, 0));
        state.platformL2.push_back(newEntity);
        state.allEntities.push_back(newEntity);
        if (-5 + i == 3 || -5 + i == -4 || -5 + i == 0) { newEntity->isActive = false; }
        newEntity->Update(0, {});
    }

    for (int i = 0; i < PLATFORML3_COUNT; i++) {
        Entity* newEntity = new Entity(EntityType::PLATFORM, textID, initialPos, 0);
        newEntity->setPosition(glm::vec3(-2 + i, 4.5f, 0));
        state.platformL3.push_back(newEntity);
        state.allEntities.push_back(newEntity);
        newEntity->Update(0, {});
    }
}

void makeLadder() {
    GLuint textID;
    glm::vec3 initialPos;
    vector<vector<float>> ladderPos{ {-1.0f, -4.5f},{3.0f,-1.5f},{-4.0f,-1.5f} };
    for (int i = 0; i < LADDER_COUNT; i++) {
        textID = LoadTexture("assets/ladder_down.png");
        initialPos = glm::vec3(ladderPos[i][0], ladderPos[i][1], 0);
        int j = 0;
        // make ladder bottom
        for (; j < 2; j++) {
            glm::vec3 pos = initialPos;
            pos.y += j;
            Entity* newEntity = new Entity(EntityType::LADDER, textID, pos, 0);
            state.ladder.push_back(newEntity);
            state.allEntities.push_back(newEntity);
            newEntity->Update(0, {});
        }
        textID = LoadTexture("assets/ladder_up.png");
        glm::vec3 pos = initialPos;
        pos.y += j;
        Entity* newEntity = new Entity(EntityType::LADDER, textID, pos, 0);
        state.ladder.push_back(newEntity);
        state.allEntities.push_back(newEntity);
        newEntity->Update(0, {});
    }

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