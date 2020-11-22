
#include "NPC.h"


NPC::NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type, int walkRadius)
    : Entity(EntityType::NPC, textID, pos, speed), aiType(type), walkRadius(walkRadius) {
    initialPos = pos;
    acceleration = glm::vec3(0);
    // set up entityType and animation data
    if (type == BUNNY) { 
        entityType = EntityType::FRIEND; 
        height = 0.8f;
        animLeft = new int[5]{ 0, 1, 2, 3, 4 };
        animRight = new int[5]{ 5 , 6 , 7, 8, 9 };
        animIndices = facing == LEFT ? animLeft : animRight;
        animFrames = 5;
        animIndex = 0;
        animTime = 0;
        animCols = 10;
        animRows = 1;
    }
    else if (type == FISH) {
        entityType = EntityType::ENEMY;
        height = 0.8f;
        animLeft = new int[4]{ 0, 1, 2, 3 };
        animRight = new int[4]{ 4, 5 , 6 , 7 };
        animIndices = facing == LEFT ? animLeft : animRight;
        animFrames = 4;
        animIndex = 0;
        animTime = 0;
        animCols = 8;
        animRows = 1;
    }
}

AIType NPC::getAIType() const { return aiType; }

void NPC::updateAIType(Mode mode) {
    if (mode == Mode::DAY) {
        if (aiType == BUNNY) { entityType = EntityType::FRIEND; }
        else if(aiType == FISH) { entityType = EntityType::ENEMY; }
    }
    else { // mode == NIGHT
        if (aiType == BUNNY) { entityType = EntityType::ENEMY; }
        else if (aiType == FISH) { entityType = EntityType::FRIEND; }
    }
}


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
