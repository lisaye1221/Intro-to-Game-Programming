
#include "Level.h"
using namespace std;


void Level::Initialize() {
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
            state.currText.nextLine();
            break;
        case SDLK_k:
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

void Level::displayUI(ShaderProgram* program, GLuint fontTextureID) const {
    Util::DrawText(program, fontTextureID, "Player x: " + to_string(state.player->getPosition().x), 1.0, -0.2, glm::vec3(2, 2, 0));
    Util::DrawText(program, fontTextureID, "Player y: " + to_string(state.player->getPosition().y), 1.0, -0.2, glm::vec3(2, 0, 0));

}

void Level::Render(ShaderProgram* program) {
    state.map->Render(program);
    state.magenta->Render(program);
    state.player->Render(program);
    Level::displayUI(program, fontTextureID);
}