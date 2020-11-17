#pragma once

#include "Entity.h"

class Player : public Entity {

public:
	Player(GLuint textID, glm::vec3 position, float speed);

	void ProcessPlayerInput(SDL_Event& event);

	void Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map);

	bool justJumped;
private:
	bool jump;
	float jumpPower;
};