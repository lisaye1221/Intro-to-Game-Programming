
#include "NPC.h"


NPC::NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, int walkRadius)
    : Entity(EntityType::NPC, textID, pos, speed), aiType(type), walkRadius(walkRadius) {
    initialPos = pos;
    acceleration = glm::vec3(0);
    if (type == FRIEND) { entityType = EntityType::FRIEND; }
    else { entityType = EntityType::ENEMY; }
}

AIType NPC::getAIType() const { return aiType; }


void NPC::Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map) {
    AI(player);
    animIndices = facing == LEFT ? animLeft : animRight;
    Entity::Update(deltaTime, entitySets, map);
}

void NPC::AI(Entity* player) {

    // moves left or right depending on where it's facing
    if (facing == LEFT) {
        movement = glm::vec3(-1, 0, 0);
    }
    else if (facing == RIGHT) {
        movement = glm::vec3(1, 0, 0);
    }

    // if go out of walking bound, turns the othe way
    if (position.x >= initialPos.x + walkRadius) {
        facing = LEFT;
    }
    else if (position.x <= initialPos.x - walkRadius) {
        facing = RIGHT;
    }



}
