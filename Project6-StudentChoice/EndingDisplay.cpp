#include "EndingDisplay.h"
#include "Util.h"

EndingDisplay::EndingDisplay(int type) {
    endingType = type;
}

void EndingDisplay::Initialize() {
    nextScene = -1;
    backgroundMatrix = glm::mat4(1.0f);
    titleMatrix = glm::mat4(1.0f);
    titleMatrix = glm::translate(titleMatrix, glm::vec3(0, 2, 0));

    // add in music for main menu

    if (endingType == 1) {
        // Start Audio
        bgm = Mix_LoadMUS("assets/audio/The-Bog-of-Despair.mp3");
        Mix_VolumeMusic(MIX_MAX_VOLUME / 7);
        // Check load
        if (bgm == NULL) {
            std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
            assert(false);
        }
        // loop the bgm
        Mix_PlayMusic(bgm, -1);
    }


    fontTextureID = Util::LoadTexture("assets/font.png");

    backgroundMatrix = glm::translate(backgroundMatrix, glm::vec3(16, -9, 0));

}

void EndingDisplay::ProcessInput(SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_RETURN:
            // move to level 1
            nextScene = 0;
        }
        break; // SDL_KEYDOWN
    }
}

void EndingDisplay::Update(float deltaTime) {

}

void EndingDisplay::Render(ShaderProgram* program, ShaderProgram* program_lit) {

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

    switch (endingType) {
    case 1: // bad end death
        Util::DrawText(program, fontTextureID, "Bad End:Death", 2.3, -0.18, glm::vec3(3, -6, 0));
        break;
    case 2: // ending 1: betrayal
        Util::DrawText(program, fontTextureID, "Ending 1:Betrayal", 1.8, -0.3, glm::vec3(3.5, -6, 0));
        break;
    case 3: // ending 2: cycle
        Util::DrawText(program, fontTextureID, "Ending 2:Cycle", 1.8, -0.3, glm::vec3(3.5, -6, 0));
        break;
    case 4: // ending 3: sacrifice
        Util::DrawText(program, fontTextureID, "Ending 3:Sacrifice", 1.8, -0.3, glm::vec3(3.5, -6, 0));
        break;
    case 5: // ending 4: welcome home
        Util::DrawText(program, fontTextureID, "Ending 4:Welcome Home", 1.5, -0.3, glm::vec3(3.5, -6, 0));
        break;
    }

    // display text to prompt user to start game
    Util::DrawText(program, fontTextureID, "Press Enter to Return to Main Menu", 1.0, -0.2, glm::vec3(3, -10, 0));

    glDisableVertexAttribArray(program->positionAttribute);
    glDisableVertexAttribArray(program->texCoordAttribute);
}

Player* EndingDisplay::getPlayer() {
    return nullptr;
}