
#include "Level.h"

void Level::ProcessInput(SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_h: // Interact
            Interact();
            break;
        case SDLK_j: // confirm/next
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
