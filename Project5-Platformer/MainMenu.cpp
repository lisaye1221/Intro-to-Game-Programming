#include "MainMenu.h"
#include "Util.h"


void MainMenu::Initialize() {
    state.nextScene = -1;
    backgroundMatrix = glm::mat4(1.0f);
    titleMatrix = glm::mat4(1.0f);
    titleMatrix = glm::translate(titleMatrix, glm::vec3(0, 2, 0));

    // add in music for main menu

    // Start Audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    bgm = Mix_LoadMUS("assets/audio/main_menu.wav");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
    // Check load
    if (bgm == NULL) {
        std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
        assert(false);
    }
    Mix_PlayMusic(bgm, -1);


    // add in graphics for main menu
    backgroundID = Util::LoadTexture("assets/background.png");
    titleID = Util::LoadTexture("assets/Title.png");
    fontTextureID = Util::LoadTexture("assets/font.png");

}

void MainMenu::Update(float deltaTime) {
    
}

void MainMenu::Render(ShaderProgram* program) {

    float vertices[] = { -5.0, -3.75, 5.0, -3.75, 5.0, 3.75, -5.0, -3.75, 5.0, 3.75, -5.0, 3.75 };
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
    float verticesTitle[] = { -4.0, -1, 4.0, -1, 4.0, 1, -4.0, -1, 4.0, 1, -4.0, 1 };
    glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, verticesTitle);
    glEnableVertexAttribArray(program->positionAttribute);
    glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program->texCoordAttribute);
    program->SetModelMatrix(titleMatrix);
    glBindTexture(GL_TEXTURE_2D, titleID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // display text to prompt user to start game

    Util::DrawText(program, fontTextureID, "Press Enter to Start", 0.5, -0.23, glm::vec3(-2.2, -0.5, 0));

    glDisableVertexAttribArray(program->positionAttribute);
    glDisableVertexAttribArray(program->texCoordAttribute);
}