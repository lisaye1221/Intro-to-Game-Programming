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
GLuint playerTextureID;
GLuint ballTextureID;

ShaderProgram program;
glm::mat4 viewMatrix, playerMatrix, projectionMatrix, ballMatrix;

float lastTicks = 0.0f;
float player_x;
float ball_x;
float ball_angle;
bool goLeft = false;
bool changeDirection = false;


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
    displayWindow = SDL_CreateWindow("Texture", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 640, 480);

    program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");

    // setting up the position variables
    player_x = 0.0f;
    ball_x = 0.0f;
    ball_angle = 0.0f;
    // setting up the matrices
    viewMatrix = glm::mat4(1.0f);
    playerMatrix = glm::mat4(1.0f);
    ballMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

    // set player to its initial position
    playerMatrix = glm::translate(playerMatrix, glm::vec3(-4.2f, -2.5f, 0.0f));
    // set ball relative to player(place it next to the player on the right)
    ballMatrix = glm::translate(playerMatrix, glm::vec3(0.65f, -0.2f, 0.0f));
    
    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);
    //program.SetColor(1.0f, 0.0f, 0.0f, 1.0f);

    glUseProgram(program.programID);

    // background color
    glClearColor(190.0f/255.0f, 230.0f/255.0f, 240.0f/255.0f, 1.0f);
    // enable blend so texture can blend with background
    glEnable(GL_BLEND);
    // Good setting for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // loading the textures from image files
    playerTextureID = LoadTexture("prince.png");
    ballTextureID = LoadTexture("ball.png");
}

void ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
            gameIsRunning = false;
        }
    }
}

void Update() { 
    
    // setting model matrix to identity matrix(resetting matrix)
    playerMatrix = glm::mat4(1.0f);
    ballMatrix = glm::mat4(1.0f);
    
    if (changeDirection) {
        // flips the player texture
        playerMatrix = glm::scale(playerMatrix, glm::vec3(-1.0f, 1.0f, 1.0f));
        // deals with the deplacement offset
        playerMatrix = glm::translate(playerMatrix, glm::vec3(-14.2f, -2.5f, 0.0f));
    }
    else {
        // set player to its initial position
        playerMatrix = glm::translate(playerMatrix, glm::vec3(-4.2f, -2.5f, 0.0f));
    }
    // set the ball to the right of player
    ballMatrix = glm::translate(playerMatrix, glm::vec3(0.65f, -0.2f, 0.0f)); 
    

    // calculating deltaTime by calculating how much time has gone by since last frame
    float ticks = (float)SDL_GetTicks() / 1000.0f;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;

    // detect when to change direction
    if (player_x > 9.0f) {
        changeDirection = true;
    }

    //if (!goLeft) { // moving to the right
        player_x += 1.0f * deltaTime;
        ball_x += 1.0f * deltaTime;
        ball_angle += -55.0f * deltaTime;
        playerMatrix = glm::translate(playerMatrix, glm::vec3(player_x, 0.0f, 0.0f));
        ballMatrix = glm::translate(ballMatrix, glm::vec3(ball_x, 0.0f, 0.0f));
        ballMatrix = glm::rotate(ballMatrix, glm::radians(ball_angle), glm::vec3(0.0f, 0.0f, 1.0f));
    //}
    //else { // moving to the left
    //    player_x -= 1.0f * deltaTime;
    //    ball_x -= 1.0f * deltaTime;
    //    ball_angle += 55.0f * deltaTime;
    //    playerMatrix = glm::translate(playerMatrix, glm::vec3(player_x, 0.0f, 0.0f));
    //    ballMatrix = glm::translate(ballMatrix, glm::vec3(ball_x, 0.0f, 0.0f));
    //    ballMatrix = glm::rotate(ballMatrix, glm::radians(ball_angle), glm::vec3(0.0f, 0.0f, 1.0f));
    //    
    //}

    

}

void Render() {
    glClear(GL_COLOR_BUFFER_BIT);


    float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
    float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
    glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program.positionAttribute);
    glVertexAttribPointer(program.texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program.texCoordAttribute);

    program.SetModelMatrix(playerMatrix);
    glBindTexture(GL_TEXTURE_2D, playerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    program.SetModelMatrix(ballMatrix);
    glBindTexture(GL_TEXTURE_2D, ballTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);


    glDisableVertexAttribArray(program.positionAttribute);
    glDisableVertexAttribArray(program.texCoordAttribute);
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
