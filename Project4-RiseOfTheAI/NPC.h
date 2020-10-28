#pragma once

#include "Entity.h"

enum AIType { RUNNER, COPIER, SLEEPER };
enum AIState { IDLE, RUNNING_AWAY, COPYING, ALARMED };

class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, AIState state = IDLE);

	AIType getType() const;
	AIState getState() const;

	void setState(AIState state);

	virtual void Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets);

	void AIRunner(Entity* player);
	void AICopier(Entity* player);
	void AISleeper(Entity* player);

private:
	void AI(Entity*);
	AIType aiType;
	AIState aiState;

};