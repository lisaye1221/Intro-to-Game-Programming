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

	if (state.gameWon) {
		Util::DrawText(program, fontTextureID, "You Win", 0.7, -0.35, glm::vec3(state.player->getPosition().x - 1, -3, 0));
	}
	else if(state.gameLost) {
		Util::DrawText(program, fontTextureID, "You Lose", 0.7, -0.35, glm::vec3(state.player->getPosition().x - 1, -3, 0));
	}
}

void Scene::gameLose() {
	Mix_Chunk* lose = Mix_LoadWAV("assets/audio/lose.wav");
	Mix_VolumeChunk(lose, MIX_MAX_VOLUME / 2);
	// stop the bgm
	Mix_HaltMusic();
	// play the losing jingle
	Mix_PlayChannel(-1, lose, 0);

}
void Scene::gameWin() {
	Mix_Chunk* win = Mix_LoadWAV("assets/audio/win.wav");
	Mix_VolumeChunk(win, MIX_MAX_VOLUME / 2);
	// stop the bgm
	Mix_HaltMusic();
	// play the winning jingle
	Mix_PlayChannel(-1, win, 0);

}