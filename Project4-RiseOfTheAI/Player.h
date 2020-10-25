#pragma once

#include "Entity.h"

class Player : public Entity {

public:
	Player(GLuint textID, glm::vec3 position, float speed);

    void ProcessPlayerInput();

	void Update(float deltaTime, const std::vector<std::pair<Entity*, int>>& entitySets);

private:
	bool jump = false;
	float jumpPower = 4.0f;

};