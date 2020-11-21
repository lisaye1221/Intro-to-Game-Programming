#pragma once

#include "Entity.h"

class Player : public Entity {

public:
	Player(GLuint textID, glm::vec3 position, float speed);

	void ProcessPlayerInput(SDL_Event& event);

	void CheckCollisionsX(Map* map);

	void Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map);

	int getLives() const;

	void hitObstacle();
	void decreaseLife();
	void increaseLife();
	void copyProgress(Player* prevPlayer);

	bool justJumped;
	bool advanceStage = false;
private:
	bool jump;
	float jumpPower;
	int lives;
	bool isInvincible = false;
};