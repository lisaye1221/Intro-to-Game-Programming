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

#include "Util.h"
#include "Entity.h"
#include "Map.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

SDL_Window* displayWindow;
bool gameIsRunning = true;

ShaderProgram program;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;

Scene* currentScene;
Scene* sceneList[4];
void SwitchToScene(Scene* prevScene, Scene* nextScene) {
    currentScene = nextScene;
    currentScene->Initialize();
    currentScene->state.player->copyProgress(prevScene->state.player);
    nextScene->bgm = prevScene->bgm;
    prevScene->bgm = nullptr;
}

void SwitchToScene(Scene* nextScene) {
    currentScene = nextScene;
    currentScene->Initialize();
}

void Initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    displayWindow = SDL_CreateWindow("Day and Night Lite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 640, 480);

    program.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl");

    viewMatrix = glm::mat4(1.0f);
    modelMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

    program.SetProjectionMatrix(projectionMatrix);
    program.SetViewMatrix(viewMatrix);

    glUseProgram(program.programID);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    sceneList[0] = new MainMenu();
    sceneList[1] = new Level1();
    sceneList[2] = new Level2();
    sceneList[3] = new Level3();
    SwitchToScene(sceneList[0]);

   
}

void ProcessInput() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            gameIsRunning = false;
            break;
        //case SDL_KEYDOWN:
        //    switch (event.key.keysym.sym) {
        //    case SDLK_a:
        //        currentScene->switchDayAndNight();
        //        break;
        //    default:
        //        currentScene->ProcessInput(event);
        //    }
        //    break; // SDL_KEYDOWN
        default:
            currentScene->ProcessInput(event);
        }
    }

}

#define FIXED_TIMESTEP 0.0166666f
float lastTicks = 0;
float accumulator = 0.0f;
void Update() {
    float ticks = (float)SDL_GetTicks() / 1000.0f;
    float deltaTime = ticks - lastTicks;
    lastTicks = ticks;
    deltaTime += accumulator;
    if (deltaTime < FIXED_TIMESTEP) {
        accumulator = deltaTime;
        return;
    }
    while (deltaTime >= FIXED_TIMESTEP) {
        // Update. Notice it's FIXED_TIMESTEP. Not deltaTime
        if (!currentScene->state.gameLost && !currentScene->state.gameWon) {
            currentScene->Update(FIXED_TIMESTEP);
        }

        deltaTime -= FIXED_TIMESTEP;
    }
    accumulator = deltaTime;

    if (!currentScene->state.player) {
        return;
    }

    viewMatrix = glm::mat4(1.0f);
    if (currentScene->state.player->getPosition().x > 5) {
        viewMatrix = glm::translate(viewMatrix, glm::vec3(-currentScene->state.player->getPosition().x, 3.75, 0));
    }
    else {
        viewMatrix = glm::translate(viewMatrix, glm::vec3(-5, 3.75, 0));
    }


}


void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    program.SetViewMatrix(viewMatrix);

    currentScene->Render(&program);

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
        if (currentScene->state.nextScene == 1) {
            SwitchToScene(sceneList[1]);

        }
        else if (currentScene->state.nextScene > 1) {
            SwitchToScene(currentScene, sceneList[currentScene->state.nextScene]);
        }
        Render();
    }

    Shutdown();
    return 0;
}
