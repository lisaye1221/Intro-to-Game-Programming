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
GLuint kingTextureID;
GLuint groundTextureID;

ShaderProgram program;
glm::mat4 viewMatrix, playerMatrix, projectionMatrix, ballMatrix, kingMatrix, groundMatrix;

float lastTicks = 0.0f;
float player_x;
float ball_x;
float ball_angle;
float king_size;
float king_x;
float king_y;
bool changedDirection = false;
float direction = 1.0f;
float kingScale = 1.0f;
float king_x_d = 1.0f;
float king_y_d = -1.0f;

void kingMovementHandler();


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
    displayWindow = SDL_CreateWindow("Let's Roll", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
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
    king_size = 0.0f;
    // setting up the matrices
    viewMatrix = glm::mat4(1.0f);
    playerMatrix = glm::mat4(1.0f);
    ballMatrix = glm::mat4(1.0f);
    kingMatrix = glm::mat4(1.0f);
    groundMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);
    
    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);

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
    kingTextureID = LoadTexture("king.png");
    groundTextureID = LoadTexture("ground.png");
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
    kingMatrix = glm::mat4(1.0f);
    groundMatrix = glm::mat4(1.0f);
    // placing the textures to their initial position
    playerMatrix = glm::translate(playerMatrix, glm::vec3(-4.2f, -2.5f, 0.0f));
    kingMatrix = glm::translate(kingMatrix, glm::vec3(0.0f, 2.8f, 0.0f));
    groundMatrix = glm::translate(groundMatrix, glm::vec3(0.0f, -3.4f, 0.0f));
    groundMatrix = glm::scale(groundMatrix, glm::vec3(10.0f, 1.0f, 1.0f));
    // set the ball to the right of player
    ballMatrix = glm::translate(playerMatrix, glm::vec3(0.65f * direction, -0.2f, 0.0f)); 

    // calculating deltaTime by calculating how much time has gone by since last frame
    float ticks = (float)SDL_GetTicks() / 1000.0f;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;

    // detect when to change direction
    if (player_x > 9.7f) { // near the right bound
        direction = -1;
    }
    if (player_x < -1.5f) { // near the left bound
        direction = 1;
    }

    // set the speed at which player/ball move/rotate
    player_x += 1.2f * (deltaTime * direction);
    ball_x += 1.2f * (deltaTime * direction);
    ball_angle += -65.0f * (deltaTime * direction);

    // adjust the direction at which king moves based on its position
    kingMovementHandler();
    // set the speed at which king moves/grows/shrinks
    king_size += 1.0f * deltaTime * kingScale;
    king_x += 1.8f * (deltaTime * king_x_d);
    king_y += 1.8f * (deltaTime * king_y_d);
    // transform the textures
    playerMatrix = glm::translate(playerMatrix, glm::vec3(player_x, 0.0f, 0.0f));
    ballMatrix = glm::translate(ballMatrix, glm::vec3(ball_x, 0.0f, 0.0f));
    ballMatrix = glm::rotate(ballMatrix, glm::radians(ball_angle), glm::vec3(0.0f, 0.0f, 1.0f));
    kingMatrix = glm::translate(kingMatrix, glm::vec3(king_x, king_y, 0.0f));
    kingMatrix = glm::scale(kingMatrix, glm::vec3(king_size, king_size, king_size));
 
    // mirror flipping the player texture when direction changes
    playerMatrix = glm::scale(playerMatrix, glm::vec3(direction, 1.0f, 1.0f));

}

void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
    float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
    glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program.positionAttribute);
    glVertexAttribPointer(program.texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program.texCoordAttribute);

    // draw the ground
    program.SetModelMatrix(groundMatrix);
    glBindTexture(GL_TEXTURE_2D, groundTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // draw the player
    program.SetModelMatrix(playerMatrix);
    glBindTexture(GL_TEXTURE_2D, playerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // draw the ball
    program.SetModelMatrix(ballMatrix);
    glBindTexture(GL_TEXTURE_2D, ballTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // draw the king
    program.SetModelMatrix(kingMatrix);
    glBindTexture(GL_TEXTURE_2D, kingTextureID);
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

// adjust the direction at which king moves based on its position
void kingMovementHandler() {
    if (king_size > 2.0f) {
        kingScale = -1;
    }
    if (king_size < 0.7f) {
        kingScale = 1;
    }
    if (king_y < -2.0f) {
        king_y_d = 1;
    }
    if (king_y > 0.5f) {
        king_y_d = -1;
    }
    if (king_x > 4.5f) {
        king_x_d = -1;
    }
    if (king_x < -4.5f) {
        king_x_d = 1;
    }
}