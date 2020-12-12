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
#include "Effects.h"
#include "Entity.h"
#include "Map.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"


SDL_Window* displayWindow;
bool gameIsRunning = true;

ShaderProgram program;
ShaderProgram program_regular;
ShaderProgram program_lit;
glm::mat4 viewMatrix, modelMatrix, projectionMatrix;

Effects* effects;

Scene* currentScene;
Scene* sceneList[10];
Scene* endingSceneList[5];
void SwitchToScene(Scene* prevScene, Scene* nextScene) {
    effects->Start(EffectType::FADEIN, 0.7f);
    currentScene = nextScene;
    currentScene->Initialize();
    prevScene->bgm = nullptr;
    currentScene->getPlayer()->copyProgress(prevScene->getPlayer());
    
}

void SwitchToScene(Scene* nextScene) {
    
    currentScene = nextScene;
    currentScene->Initialize();
}

void Initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    displayWindow = SDL_CreateWindow("This World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
    SDL_GL_MakeCurrent(displayWindow, context);

#ifdef _WINDOWS
    glewInit();
#endif

    glViewport(0, 0, 640, 480);

    program_regular.Load("shaders/vertex_textured.glsl", "shaders/fragment_textured.glsl"); 
    program_lit.Load("shaders/vertex_lit.glsl", "shaders/fragment_lit.glsl");
    

    viewMatrix = glm::mat4(1.0f);
    modelMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::ortho(-16.0f, 16.0f, -12.0f, 12.0f, -1.0f, 1.0f);

    program_regular.SetProjectionMatrix(projectionMatrix);
    program_regular.SetViewMatrix(viewMatrix);
    program_lit.SetProjectionMatrix(projectionMatrix);
    program_lit.SetViewMatrix(viewMatrix);

    program = program_regular;
    glUseProgram(program.programID);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    viewMatrix = glm::translate(viewMatrix, glm::vec3(-16, 9, 0));

    effects = new Effects(projectionMatrix, viewMatrix);

    sceneList[0] = new MainMenu();
    sceneList[1] = new Level1();
    sceneList[2] = new Level2();
    sceneList[3] = new Level3();
    sceneList[4] = new Level4();
    sceneList[5] = new Level5();
    sceneList[6] = new Level6();
    
    SwitchToScene(sceneList[6]);
   
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
        currentScene->Update(FIXED_TIMESTEP);
        
        if (currentScene->getWorldNum() == 4) { program.SetLightPosition(currentScene->getPlayer()->getPosition()); }

        effects->Update(FIXED_TIMESTEP);
        deltaTime -= FIXED_TIMESTEP;
    }
    accumulator = deltaTime;

    viewMatrix = glm::mat4(1.0f);
    if (currentScene->viewScrolls) {
        if (currentScene->getPlayer()->getPosition().x > 52.5) {
            viewMatrix = glm::translate(viewMatrix, glm::vec3(-52.5, 9, 0));
        }
        else if (currentScene->getPlayer()->getPosition().x > 16) {
            viewMatrix = glm::translate(viewMatrix, glm::vec3(-currentScene->getPlayer()->getPosition().x, 9, 0));
        }
        else {
            viewMatrix = glm::translate(viewMatrix, glm::vec3(-16, 9, 0));
        }
    }
    else {
        viewMatrix = glm::translate(viewMatrix, glm::vec3(-16, 9, 0));

    }
    
    if (currentScene->effect != EffectType::NONE) {
        effects->Start(currentScene->effect, currentScene->effectSpd);
        currentScene->effect = EffectType::NONE;
    }

}


void Render() {
    glClear(GL_COLOR_BUFFER_BIT);

    program_regular.SetViewMatrix(viewMatrix);
    program_lit.SetViewMatrix(viewMatrix);

    glUseProgram(program.programID);
    currentScene->getWorldNum() == 4? currentScene->Render(&program_regular, &program_lit) : currentScene->Render(&program);
    
    effects->Render();
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
        if (currentScene->nextScene == 1) {
            effects->Start(EffectType::FADEIN, 0.5f);
            SwitchToScene(sceneList[1]);

        }
        else if (currentScene->nextScene > 1) {
            if (currentScene->nextScene == 4) {
                program = program_lit;
            }
            if (currentScene->nextScene == 5) {
                program = program_regular;
            }
            SwitchToScene(currentScene, sceneList[currentScene->nextScene]);
        }
        Render();
    }

    Shutdown();
    return 0;
}
