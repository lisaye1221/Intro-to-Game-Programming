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
#include<vector>

SDL_Window* displayWindow;
bool gameIsRunning = true;
bool startGame = false;
bool leftLost = false;
bool rightLost = false;

ShaderProgram program;
glm::mat4 viewMatrix, projectionMatrix;
glm::mat4 leftPlayerMatrix;
glm::mat4 rightPlayerMatrix;
glm::mat4 ballMatrix;

// Start at their respective positions
glm::vec3 left_player_position = glm::vec3(-4.8f, 0.0f, 0);
glm::vec3 right_player_position = glm::vec3(4.8f, 0.0f, 0);
glm::vec3 ball_position = glm::vec3(0, 0, 0);
// Don’t go anywhere (yet).
glm::vec3 left_player_movement = glm::vec3(0, 0, 0);
glm::vec3 right_player_movement = glm::vec3(0, 0, 0);
// Ball should automaically start moving
glm::vec3 ball_movement = glm::vec3(-0.5, -1.0, 0);

float left_player_speed = 2.5f;
float right_player_speed = 2.5f;
float ball_speed = 3.5f;

GLuint fontTextureID;
GLuint leftPlayerTextureID;
GLuint rightPlayerTextureID;
GLuint ballTextureID;

float lastTicks = 0.0f;
float pauseTicks = 0.0f;

// function prototypes
void DrawText(ShaderProgram* program, GLuint fontTextureID, const std::string& text,
    float size, float spacing, glm::vec3 position);
void textDisplay();
void detectCollision();

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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
    program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl" );

    viewMatrix = glm::mat4(1.0f);
    leftPlayerMatrix = glm::mat4(1.0f);
    rightPlayerMatrix = glm::mat4(1.0f);
    ballMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

    // set up initial position
    leftPlayerMatrix = glm::translate(leftPlayerMatrix, left_player_position);
    rightPlayerMatrix = glm::translate(rightPlayerMatrix, right_player_position);

    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);
    // the rectangle color: (r, b, g, alpha)
    program.SetColor(1.0f, 1.0f, 1.0f, 1.0f); // white

    glUseProgram(program.programID);

    // background color
    glClearColor(250.0f/255.0f, 243.0f/255.0f, 209.0f/255.0f, 1.0f);
    // enable blend so texture can blend with background
    glEnable(GL_BLEND);
    // Good setting for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // loading the textures from image files
    fontTextureID = LoadTexture("font1.png");
    leftPlayerTextureID = LoadTexture("baguette-left.png");
    rightPlayerTextureID = LoadTexture("baguette-right.png");
    ballTextureID = LoadTexture("square.jpg");
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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				// press space bar = starts the game
				startGame = true;
                // to subtract from deltaTime: we don't want to count the amount of time when game hasn't start
                pauseTicks = (float)SDL_GetTicks() / 1000.0f - lastTicks;
				break;
			}
			break; // SDL_KEYDOWN
        }

    }
    if (startGame && !leftLost && !rightLost) { // process input only if game has started
        const Uint8* keys = SDL_GetKeyboardState(NULL);
        // if 'W' key is held down, left player moves up
        if (keys[SDL_SCANCODE_W]) {
            if (left_player_position.y < 2.75f) { // upper bound
                left_player_movement.y = 1.0f;
            }
        }
        // if 'S' key is held down, left player moves down
        else if (keys[SDL_SCANCODE_S]) {
            if (left_player_position.y > -2.75f) { // lower bound
                left_player_movement.y = -1.0f;
            }
        }
        // if up arrow is held down, right player moves up
        if (keys[SDL_SCANCODE_UP]) {
            if (right_player_position.y < 2.75f) {
                right_player_movement.y = 1.0f;
            }
        }
        // if up arrow is held down, right player moves down
        else if (keys[SDL_SCANCODE_DOWN]) {
            if (right_player_position.y > -2.75f) {
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
}


void Update() {

    detectCollision();
    
    float ticks = (float)SDL_GetTicks() / 1000.0f - pauseTicks;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;
    // Add (direction * units per second * elapsed time)
    // updating players' positions
    left_player_position += left_player_movement * left_player_speed * deltaTime;
    right_player_position += right_player_movement * right_player_speed * deltaTime;
    ball_position += ball_movement * ball_speed * deltaTime;
    // reset matrices so it doesn't accumulate 
    leftPlayerMatrix = glm::mat4(1.0f);
    rightPlayerMatrix = glm::mat4(1.0f);
    ballMatrix = glm::mat4(1.0f);
    // update transformation
    leftPlayerMatrix = glm::translate(leftPlayerMatrix, left_player_position);
    rightPlayerMatrix = glm::translate(rightPlayerMatrix, right_player_position);
    ballMatrix = glm::translate(ballMatrix, ball_position);
    
}

void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    float verticesTwo[] = { -0.25, -0.25, 0.25, -0.25, 0.25, 0.25, -0.25, -0.25, 0.25, 0.25, -0.25, 0.25 };
    float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
    glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, verticesTwo);
    glEnableVertexAttribArray(program.positionAttribute);
    glVertexAttribPointer(program.texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program.texCoordAttribute);

    program.SetModelMatrix(ballMatrix);
    glBindTexture(GL_TEXTURE_2D, ballTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    float vertices[] = { -0.25, -1.0, 0.25, -1.0, 0.25, 1.0, -0.25, -1.0, 0.25, 1.0, -0.25, 1.0 };
    //float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
    glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program.positionAttribute);
    glVertexAttribPointer(program.texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program.texCoordAttribute);

    // draw the player
    program.SetModelMatrix(leftPlayerMatrix);
    glBindTexture(GL_TEXTURE_2D, leftPlayerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // draw the player
    program.SetModelMatrix(rightPlayerMatrix);
    glBindTexture(GL_TEXTURE_2D, rightPlayerTextureID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    textDisplay();

    glDisableVertexAttribArray(program.positionAttribute);
    glDisableVertexAttribArray(program.texCoordAttribute);
    SDL_GL_SwapWindow(displayWindow);
}

void Shutdown() {
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    Initialize();
    Render();

    while (gameIsRunning) {
        ProcessInput();
        if (startGame) { // if the game is not paused/has not started
            Update();
            Render();
        }
    }

    Shutdown();
    return 0;
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
    if (!startGame) {
        DrawText(&program, fontTextureID, "Press the space bar to begin", 0.5, -0.30, glm::vec3(-2.5, 0.5, 0));
        DrawText(&program, fontTextureID, "Left Player: W & S key", 0.4, -0.25, glm::vec3(-2.0, 0, 0));
        DrawText(&program, fontTextureID, "Right Player: up & down arrow", 0.4, -0.25, glm::vec3(-2.0, -0.5, 0));
    }
    if (leftLost) {
        DrawText(&program, fontTextureID, "Right Player Wins", 0.4, -0.25, glm::vec3(-1.0, 0, 0));

    }
    if (rightLost) {
        DrawText(&program, fontTextureID, "Left Player Wins", 0.4, -0.25, glm::vec3(-1.0, 0, 0));
    }
}

void detectCollision() {
    // Test Collision
    // left player and ball
    float xdist = fabs(left_player_position.x - ball_position.x) - ((0.5f + 0.5f) / 2.0f);
    float ydist = fabs(left_player_position.y - ball_position.y) - ((2.0f + 0.5f) / 2.0f);
    if (xdist < 0 && ydist < 0) {
        ball_movement.x *= -1;
    }
    // right player and ball
    xdist = fabs(right_player_position.x - ball_position.x) - ((0.5f + 0.5f) / 2.0f);
    ydist = fabs(right_player_position.y - ball_position.y) - ((2.0f + 0.5f) / 2.0f);
    if (xdist < 0 && ydist < 0) {
        ball_movement.x *= -1;
    }

    // Testing if ball hits top and bottom
    if (ball_position.y > 3.5f) { //top
        ball_position.y = 3.5f;
        ball_movement.y *= -1;
    }
    if (ball_position.y < -3.5f) { //bottom
        ball_position.y = -3.5f;
        ball_movement.y *= -1;
    }

    // Testing if ball hits left and right boundary
    if (ball_position.x < -4.75f) { //left
        leftLost = true;
        ball_speed = 0;
    }
    if (ball_position.x > 4.75f) { //right
        rightLost = true;
        ball_speed = 0;
    }
}
