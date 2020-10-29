
#include "NPC.h"


NPC::NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, AIState state)
    : Entity(EntityType::ENEMY, textID, pos, speed), aiType(type), aiState(state) {

}

AIType NPC::getAIType() const { return aiType; }
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
        AICopier(player);
        break;
    case SLEEPER:
        AISleeper(player);
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
        if (dist < 3 && player->getPosition().y < -3.5f) {
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
        if (dist >= 3) {
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
    bool isPlayerOnLevelTwo = player->getPosition().y >= -1.64f && player->getPosition().y < 0.5f ;
    switch (aiState) {
    case IDLE:
        // if player is on second level
        if (isPlayerOnLevelTwo) {
            aiState = COPYING;
        }
        break;
    case COPYING:
        if (!isPlayerOnLevelTwo) {
            aiState = IDLE;
            movement.x = 0;
            break;
        }
        movement.x = player->getMovement().x;
        break;
    }
}

void NPC::AISleeper(Entity* player) {
    bool isPlayerNotOnLevelThree = player->getPosition().y < 0.5f;
    bool isPlayerOnLeft = player->getPosition().x < position.x;
    switch (aiState) {
    case IDLE:
        if (!isPlayerNotOnLevelThree) {
            if (isPlayerOnLeft && facing == LEFT) {
                aiState = ALARMED;
                // move up to the 4th level
            }
            else if (!isPlayerOnLeft && facing == RIGHT) {
                aiState = ALARMED;
                // move up to the 4th level
                
            }
        }
        break;
    case ALARMED:
        if (!isPlayerNotOnLevelThree) {
            // move back down to level three

            // change state
            aiState = IDLE;
            break;
        }
        movement.x = player->getMovement().x;
        break;
    }
}