
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

    float leftDistance;
    float rightDistance;

    if (position.x > player->getPosition().x) {
        leftDistance = abs(position.x - player->getPosition().x);
        rightDistance = 10 - abs(position.x - player->getPosition().x);
    }
    else {
        rightDistance = abs(position.x - player->getPosition().x);
        leftDistance = 10 - abs(position.x - player->getPosition().x);
    }
    float dist;
    Direction run;

    if (leftDistance < rightDistance) {
        dist = leftDistance;
        run = RIGHT;
    }
    else {
        dist = rightDistance;
        run = LEFT;
    }

    switch (aiState) {
    case IDLE:
        if (dist < 2) {
            aiState = RUNNING_AWAY;
        }
        if (player->getPosition().x < position.x) {
            facing = LEFT;
        }
        else if (player->getPosition().x < position.x) {
            facing = RIGHT;
        }
        break;
    case RUNNING_AWAY:
        if (dist >= 2) {
            movement = glm::vec3(0);
            aiState = IDLE;
            break;
        }
        else if (run == RIGHT) {
            // move right
            movement = glm::vec3(1.3, 0, 0);
        }
        else if(run == LEFT) {
            // move left
            movement = glm::vec3(-1.3, 0, 0);
        }
        break;
    }
}

void NPC::AICopier(Entity* player) {
    switch (aiState) {
    case IDLE:
        // if player is on second level
        if (player->getPosition().y >= -2.5f && player->getPosition().y < 0.5f) {
            aiState = COPYING;
        }
        break;
    case COPYING:
        movement.x = player->getMovement().x;
        break;
    }
}

void NPC::AISleeper(Entity* player) {

}