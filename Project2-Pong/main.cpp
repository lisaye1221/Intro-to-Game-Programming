#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

SDL_Window* displayWindow;
bool gameIsRunning = true;

ShaderProgram program;
glm::mat4 viewMatrix, projectionMatrix;
glm::mat4 leftPlayerMatrix;
glm::mat4 rightPlayerMatrix;

// Start at their respective positions
glm::vec3 left_player_position = glm::vec3(-5.0f, 1.0f, 0);
glm::vec3 right_player_position = glm::vec3(5.0f, 1.0f, 0);
// Don’t go anywhere (yet).
glm::vec3 left_player_movement = glm::vec3(0, 0, 0);
glm::vec3 right_player_movement = glm::vec3(0, 0, 0);

float left_player_speed = 2.5f;
float right_player_speed = 2.5f;

float left_player_y = 0.0f;
float right_player_y = 0.0f;

GLuint playerTextureID;

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
    // (name Of window, centers window, dimentions of window, openGL context)
    displayWindow = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    // get the context of window
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 640, 480);

    // setting up shader program
    program.Load("shaders/vertex.glsl", "shaders/fragment.glsl");

    viewMatrix = glm::mat4(1.0f);
    leftPlayerMatrix = glm::mat4(1.0f);
    rightPlayerMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);


    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);
    // the rectangle color: (r, b, g, alpha)
    program.SetColor(1.0f, 1.0f, 1.0f, 1.0f); // white

    glUseProgram(program.programID);

    // background color
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    // enable blend so texture can blend with background
    glEnable(GL_BLEND);
    // Good setting for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // loading the textures from image files
    playerTextureID = LoadTexture("ctg.png");
}

void ProcessInput() {

    // reset the player's movement, doesn't move anywhere if no keys are pressed
    left_player_movement = glm::vec3(0);
    right_player_movement = glm::vec3(0);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            gameIsRunning = false;
            break;
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(NULL);
    // if 'W' key is held down, left player moves up
    if (keys[SDL_SCANCODE_W]) { 
        if (left_player_position.y < 3.5f) { // upper bound
            left_player_movement.y = 1.0f;
        }
    }
    // if 'S' key is held down, left player moves down
    else if (keys[SDL_SCANCODE_S]) {
        if (left_player_position.y > -1.8f) { // lower bound
            left_player_movement.y = -1.0f;
        }
    }
    // if up arrow is held down, right player moves up
    if (keys[SDL_SCANCODE_UP]) { 
        if (right_player_position.y < 3.5) {
            right_player_movement.y = 1.0f;
        }
    }
    // if up arrow is held down, right player moves down
    else if (keys[SDL_SCANCODE_DOWN]) {
        if (right_player_position.y > -1.8f) {
            right_player_movement.y = -1.0f;
        }
    }
    // make sure holding down two keys will maintain the same speed
    if (glm::length(left_player_movement) > 1.0f) {
        left_player_movement = glm::normalize(left_player_movement);
    }
    if (glm::length(right_player_movement) > 1.0f) {
        right_player_movement = glm::normalize(right_player_movement);
    }
}

float lastTicks = 0.0f;

void Update() {


    float ticks = (float)SDL_GetTicks() / 1000.0f;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;
    // Add (direction * units per second * elapsed time)
    // updating players' positions
    left_player_position += left_player_movement * left_player_speed * deltaTime;
    right_player_position += right_player_movement * right_player_speed * deltaTime;
    // reset matrices so it doesn't accumulate 
    leftPlayerMatrix = glm::mat4(1.0f);
    rightPlayerMatrix = glm::mat4(1.0f);
    // update transformation
    leftPlayerMatrix = glm::translate(leftPlayerMatrix, left_player_position);
    rightPlayerMatrix = glm::translate(rightPlayerMatrix, right_player_position);
}

void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = { -0.25, -2.0, 0.25, -2.0, 0.25, 0.25, -0.25, -2.0, 0.25, 0.25, -0.25, 0.25 };
    //float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
    glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program.positionAttribute);
    //glVertexAttribPointer(program.texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program.texCoordAttribute);


    // draw the player
    program.SetModelMatrix(leftPlayerMatrix);
    //glBindTexture(GL_TEXTURE_2D, playerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // draw the player
    program.SetModelMatrix(rightPlayerMatrix);
    //glBindTexture(GL_TEXTURE_2D, playerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);



   /* program.SetModelMatrix(rightPlayerMatrix);
    glBindTexture(GL_TEXTURE_2D, playerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);*/

    glDisableVertexAttribArray(program.positionAttribute);
    //glDisableVertexAttribArray(program.texCoordAttribute);
    SDL_GL_SwapWindow(displayWindow);
}

void Shutdown() {
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
