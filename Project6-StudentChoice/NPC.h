#pragma once

#include "Entity.h"


class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed, EntityType type);

	virtual void Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map);

	void CheckCollisionsX(Map* map);
	void CheckCollisionsY(Map* map);
	bool goLeftOrRight;
	bool shouldStop = false;

	void setType(EntityType type);

private:
	void AI(Entity*);
	void AI_MONSTER(Entity*);
	void AI_CHASER(Entity*);
	void AI_FAKEMONSTER(Entity*);
	void AI_MAGENTA_B(Entity*);
	glm::vec3 initialPos;
	
};