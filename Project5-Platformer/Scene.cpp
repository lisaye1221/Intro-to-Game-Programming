#include "Scene.h"



void Scene::ProcessInput(SDL_Event& event) {
	state.player->ProcessPlayerInput(event);
}