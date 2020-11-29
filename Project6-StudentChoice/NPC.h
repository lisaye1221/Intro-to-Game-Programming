#pragma once

#include "Entity.h"


class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed,  int walkRadius);

	virtual void Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map);


private:
	void AI(Entity*);
	int walkRadius;
	glm::vec3 initialPos;
};