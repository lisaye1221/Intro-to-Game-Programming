#pragma once

#include "Entity.h"


class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed, EntityType type);

	virtual void Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map);

	std::vector<std::vector<std::string>> lines;
private:
	void AI(Entity*);
	glm::vec3 initialPos;
	
};