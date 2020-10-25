#pragma once

#include "Entity.h"

enum AIType { SHOOTER, RUNNER, COPIER, SLEEPER };
enum AIState { IDLE, RUNNING_AWAY, COPYING, ALARMED };

class NPC : public Entity {

public:
	NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, AIState state = IDLE) 
		: Entity(EntityType::ENEMY, textID, pos, speed), aiType(type), aiState(state) {

	}

	AIType getType() const { return aiType; }
	AIState getState() const { return aiState; }

	void setType(AIType type) { aiType = type; }
	void setState(AIState state) { aiState = state; }

	virtual void Update(float deltaTime, Entity* player, const std::vector<std::pair<Entity*, int>>& entitySets) {
		AI(player);
		Entity::Update(deltaTime, entitySets);
	}

private:
	void AI(Entity*) {}
	AIType aiType;
	AIState aiState;

};