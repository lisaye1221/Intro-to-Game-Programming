#pragma once

#include "Entity.h"
#include <SDL_mixer.h>

class Player : public Entity {

public:
	Player(GLuint textID, glm::vec3 position, float speed);

	void ProcessPlayerInput(SDL_Event& event);

	void CheckCollisionsX(Map* map);

	void Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map);

	
	
	// void copyProgress(Player* prevPlayer);

	bool advanceStage = false;
private:
	int lives;
	bool isInvincible = false;
	int magentaTalks = 0;

	Mix_Chunk* contactSfx;
	Mix_Chunk* alertSfx;

};