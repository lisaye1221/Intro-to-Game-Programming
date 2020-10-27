
#include "NPC.h"


NPC::NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, AIState state)
    : Entity(EntityType::ENEMY, textID, pos, speed), aiType(type), aiState(state) {

}

AIType NPC::getType() const { return aiType; }
AIState NPC::getState() const { return aiState; }

void NPC::setState(AIState state) { aiState = state; }

void NPC::Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets) {
    AI(player);
    Entity::Update(deltaTime, entitySets);
}

void NPC::AI(Entity* player) {

    switch (aiType) {
    case RUNNER:
        AIRunner(player);
        break;
    case COPIER:
        break;
    case SLEEPER:
        break;
    }

}

void NPC::AIRunner(Entity* player) {
    switch (aiState) {
    case IDLE:
        if (glm::distance(position, player->getPosition()) < 3.0f) {
            aiState = RUNNING_AWAY;
        }
        break;
    case RUNNING_AWAY:
        // if player is to left of AI
        if (player->getPosition().x < position.x) {
            // move right
            movement = glm::vec3(1, 0, 0);
        }
        else { // if player is to the right
            // move left
            movement = glm::vec3(-1, 0, 0);
        }
        break;
    }
}