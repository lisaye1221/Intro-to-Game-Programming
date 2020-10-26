#pragma once

#include "Entity.h"

enum AIType { SHOOTER, RUNNER, COPIER, SLEEPER };
enum AIState { IDLE, RUNNING_AWAY, COPYING, ALARMED };

class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, AIState state = IDLE);

	AIType getType() const;
	AIState getState() const;

	void setState(AIState state);

	virtual void Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets);

private:
	void AI(Entity*);
	AIType aiType;
	AIState aiState;

};