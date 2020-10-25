

#include "NPC.h"


/*

void Entity::AIWaitAndGo(Entity* player) {
    switch (aiState) {
    case IDLE:
        if (glm::distance(position, player->position) < 3.0f) {
            aiState = WALKING;
        }
        break;
    case WALKING:
        // if player is to left of AI
        if (player->position.x < position.x) {
            // move left
            movement = glm::vec3(-1, 0, 0);
        }
        else { // if player is to the right
            // move right
            movement = glm::vec3(1, 0, 0);
        }
        break;
    case ATTACKING:
        break;
    }
}
*/

void NPC::AI(Entity* player) {

    switch (aiType) {
    case SHOOTER:
        break;
    }

}