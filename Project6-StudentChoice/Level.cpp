
#include "Level.h"
using namespace std;


void Level::Initialize() {
    nextScene = -1;
    fontTextureID = Util::LoadTexture("assets/font.png");
}

void Level::ProcessInput(SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_h: // Interact
            if (!state.player->isInteracting) { // so the player goes through an interaction before trying to reinitiate another one
                Interact();
            }
            break;
        case SDLK_j: // confirm/next
            if (toMakeChoice) { 
                buttonChoice = ButtonChoice::CONFIRM; 
                toMakeChoice = false;
            }
            state.currText.nextLine();
            break;
        case SDLK_k:
            if (toMakeChoice) { 
                buttonChoice = ButtonChoice::CANCEL; 
                toMakeChoice = false;
            }
            break;
        }
        break; // SDL_KEYDOWN
    default:
        state.player->ProcessPlayerInput(event);
    }
    
}

Player* Level::getPlayer() {
	return state.player;
}

int Level::getWorldNum() const {
    return worldNum;
}

void Level::displayUI(ShaderProgram* program, GLuint fontTextureID) const {

    float x = state.player->getPosition().x;

    if (!viewScrolls) {
        Util::DrawText(program, fontTextureID, "x: " + to_string(state.player->getPosition().x), 0.7, -0.17, glm::vec3(2, 2, 0));
        Util::DrawText(program, fontTextureID, "y: " + to_string(state.player->getPosition().y), 0.7, -0.17, glm::vec3(2, 0, 0));
        Util::DrawText(program, fontTextureID, "IsInteract: " + to_string(state.player->isInteracting), 1.0, -0.2, glm::vec3(20, 0, 0));
    }
    else {
        if (state.player->getPosition().x > 52.5) {
            Util::DrawText(program, fontTextureID, "x: " + to_string(state.player->getPosition().x), 0.7, -0.17, glm::vec3(38.5, 2, 0));
            Util::DrawText(program, fontTextureID, "y: " + to_string(state.player->getPosition().y), 0.7, -0.17, glm::vec3(38.5, 0, 0));
        }
        else if (state.player->getPosition().x > 16) {
            Util::DrawText(program, fontTextureID, "x: " + to_string(state.player->getPosition().x), 0.7, -0.17, glm::vec3(x - 14, 2, 0));
            Util::DrawText(program, fontTextureID, "y: " + to_string(state.player->getPosition().y), 0.7, -0.17, glm::vec3(x - 14, 0, 0));
        }
        else {
            Util::DrawText(program, fontTextureID, "x: " + to_string(state.player->getPosition().x), 0.7, -0.17, glm::vec3(2, 2, 0));
            Util::DrawText(program, fontTextureID, "y: " + to_string(state.player->getPosition().y), 0.7, -0.17, glm::vec3(2, 0, 0));
        }
    }

}

void Level::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    state.map->Render(program);
    for (NPC* enemy : state.enemies) {
        enemy->Render(program);
    }
    for (Entity* object : state.objects) {
        object->Render(program);
    }
    state.magenta->Render(program);
    state.player->Render(program);
    //Level::displayUI(program, fontTextureID);
}