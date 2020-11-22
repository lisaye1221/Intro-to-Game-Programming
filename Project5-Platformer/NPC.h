#pragma once

#include "Entity.h"

enum AIType { FRIEND, ENEMY };

class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, int walkRadius);

	AIType getAIType() const;

	virtual void Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map);


private:
	void AI(Entity*);
	AIType aiType;
	int walkRadius;
	glm::vec3 initialPos;
};