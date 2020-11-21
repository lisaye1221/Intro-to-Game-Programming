#include "Scene.h"

using namespace std;

void Scene::ProcessInput(SDL_Event& event) {
	state.player->ProcessPlayerInput(event);
}

void Scene::displayText(ShaderProgram* program, GLuint fontTextureID) {

	if (state.player->getPosition().x > 5) {
		Util::DrawText(program, fontTextureID, "Lives: " + to_string(state.player->getLives()), 0.5, -0.23, glm::vec3(state.player->getPosition().x - 4, -0.5, 0));
	}
	else {
		Util::DrawText(program, fontTextureID, "Lives: " + to_string(state.player->getLives()), 0.5, -0.23, glm::vec3(1, -0.5, 0));
	}
}

void Scene::gameLose() {

}
void Scene::gameWin() {

}