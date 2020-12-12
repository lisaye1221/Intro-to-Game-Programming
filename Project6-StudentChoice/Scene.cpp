#include "Scene.h"

using namespace std;

void Scene::initSfx() {
	/*clockSfx = Mix_LoadWAV("assets/audio/clock.wav");
	nextLevelSfx = Mix_LoadWAV("assets/audio/next_level.wav");*/
}
int Scene::getWorldNum() const {
	return worldNum;
}

void Scene::playEffect(EffectType type, float spd) {
	effect = type;
	effectSpd = spd;
}