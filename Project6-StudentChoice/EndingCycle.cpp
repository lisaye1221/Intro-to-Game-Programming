#include "EndingCycle.h"
#include "Util.h"
#define ENDINGCYCLE_WIDTH 33
#define ENDINGCYCLE_HEIGHT 18

unsigned int endingcycle_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 01, 34, 35, 34, 01, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 01, 35, 34, 35, 01, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 34, 35, 34, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49,
    56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57,
    48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49,
    56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57,
    48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49,
    56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void EndingCycle::Initialize() {
    nextScene = -1;
    backgroundMatrix = glm::mat4(1.0f);
    titleMatrix = glm::mat4(1.0f);
    titleMatrix = glm::translate(titleMatrix, glm::vec3(0, 2, 0));

    // add in music for main menu

    // Start Audio
    //bgm = Mix_LoadMUS("assets/audio/The-Bog-of-Despair.mp3");
    //Mix_VolumeMusic(MIX_MAX_VOLUME / 7);
    //// Check load
    //if (bgm == NULL) {
    //    std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
    //    assert(false);
    //}
    //// loop the bgm
    //Mix_PlayMusic(bgm, -1);

    GLuint mapTextureID = Util::LoadTexture("assets/world.png");
    map = new Map(ENDINGCYCLE_WIDTH, ENDINGCYCLE_HEIGHT, endingcycle_data, mapTextureID, 1.0f, 8, 8, WORLD);


    fontTextureID = Util::LoadTexture("assets/font.png");

    backgroundMatrix = glm::translate(backgroundMatrix, glm::vec3(16, -9, 0));

}

void EndingCycle::ProcessInput(SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_RETURN:
            // move to level 1
            if (showEnding) { nextScene = 0; }
        }
        break; // SDL_KEYDOWN
    }
}

void EndingCycle::Update(float deltaTime) {
    magenta->Update(deltaTime, nullptr, {}, map);


}

void EndingCycle::Render(ShaderProgram* program, ShaderProgram* program_lit) {

    if (showEnding) {
        float vertices[] = { -16.0, -12.0, 16.0, -12, 16.0, 12.0, -16, -12.0, 16.0, 12, -16, 12 };
        float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
        glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, vertices);
        glEnableVertexAttribArray(program->positionAttribute);
        glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
        glEnableVertexAttribArray(program->texCoordAttribute);

        // draw the background
        program->SetModelMatrix(backgroundMatrix);
        glBindTexture(GL_TEXTURE_2D, backgroundID);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        Util::DrawText(program, fontTextureID, "Ending 1:Betrayal", 2.3, -0.18, glm::vec3(3, -6, 0));


        // display text to prompt user to start game


        Util::DrawText(program, fontTextureID, "Press Enter to Return to Main Menu", 1.0, -0.2, glm::vec3(3, -10, 0));

        glDisableVertexAttribArray(program->positionAttribute);
        glDisableVertexAttribArray(program->texCoordAttribute);
    }
    else {
        map->Render(program);
        magenta->Render(program);
    }

    
}

Player* EndingCycle::getPlayer() {
    return nullptr;
}