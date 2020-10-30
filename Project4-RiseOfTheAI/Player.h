#pragma once

#include "Entity.h"

class Player : public Entity {

public:
	Player(GLuint textID, glm::vec3 position, float speed);

	int getBunniesCaptured() const;

	void ProcessPlayerInput(SDL_Event event);

	void Update(float deltaTime, const std::vector<Entity*>& entitySets);

	bool justCapturedBunny;
	bool justJumped;
private:
	bool jump;
	float jumpPower;
	bool onLadder() const;
	int bunniesCaptured;
};