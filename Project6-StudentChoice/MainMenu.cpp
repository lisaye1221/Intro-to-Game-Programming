#include "MainMenu.h"
#include "Util.h"


void MainMenu::Initialize() {
    nextScene = -1;
    backgroundMatrix = glm::mat4(1.0f);
    titleMatrix = glm::mat4(1.0f);
    titleMatrix = glm::translate(titleMatrix, glm::vec3(0, 2, 0));

    // add in music for main menu

    // Start Audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    bgm = Mix_LoadMUS("assets/audio/Enchanted-Forest-Open.wav");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 8);
    // Check load
    if (bgm == NULL) {
        std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
        assert(false);
    }
    // loop the bgm
    Mix_PlayMusic(bgm, -1);

    // add in graphics for main menu
    backgroundID = Util::LoadTexture("assets/background.png");
    //titleID = Util::LoadTexture("assets/Title.png");
    fontTextureID = Util::LoadTexture("assets/font.png");

    backgroundMatrix = glm::translate(backgroundMatrix, glm::vec3(16, -9, 0));

}

void MainMenu::ProcessInput(SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_RETURN:
            // move to level 1
            nextScene = 1;
            // get rid of music
            Mix_FreeMusic(bgm);
        }
        break; // SDL_KEYDOWN
    }
}

void MainMenu::Update(float deltaTime) {
    
}

void MainMenu::Render(ShaderProgram* program) {

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

    // draw the title 
    /*float verticesTitle[] = { -4.0, -1, 4.0, -1, 4.0, 1, -4.0, -1, 4.0, 1, -4.0, 1 };
    glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, verticesTitle);
    glEnableVertexAttribArray(program->positionAttribute);
    glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program->texCoordAttribute);
    program->SetModelMatrix(titleMatrix);
    glBindTexture(GL_TEXTURE_2D, titleID);
    glDrawArrays(GL_TRIANGLES, 0, 6);*/

    Util::DrawText(program, fontTextureID, "THIS WORLD", 2.4, -0.18, glm::vec3(7, -4, 0));


    // display text to prompt user to start game


    Util::DrawText(program, fontTextureID, "Press Enter to Start", 1.0, -0.2, glm::vec3(9, -8, 0));

    glDisableVertexAttribArray(program->positionAttribute);
    glDisableVertexAttribArray(program->texCoordAttribute);
}

Player* MainMenu::getPlayer() {
    return nullptr;
}