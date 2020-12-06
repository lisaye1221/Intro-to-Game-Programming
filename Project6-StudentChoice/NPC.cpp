
#include "NPC.h"


NPC::NPC(GLuint textID, const glm::vec3& pos, float speed, EntityType type)
    : Entity(type, textID, pos, speed) {
    initialPos = pos;
    // set up entityType and animation data
    if (type == EntityType::MAGENTA) {
        animRight = new int[4]{ 8, 9, 10, 11 };
        animLeft = new int[4]{ 4, 5, 6, 7 };
        animUp = new int[4]{ 12, 13, 14, 15 };
        animDown = new int[4]{ 0, 1, 2, 3 };

        animIndices = animDown;
        animFrames = 4;
        animIndex = 0;
        animTime = 0;
        animCols = 4;
        animRows = 4;
        facing = DOWN;
        height = 0.6f;
    }
    
}


void NPC::Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map) {
    AI(player);
    switch (facing) {
    case LEFT:
        animIndices = animLeft;
        break;
    case RIGHT:
        animIndices = animRight;
        break;
    case UP:
        animIndices = animUp;
        break;
    case DOWN:
        animIndices = animDown;
        break;
    }
    Entity::Update(deltaTime, entitySets, map);
}

void NPC::AI(Entity* player) {

    //// moves left or right depending on where it's facing
    //if (facing == LEFT) {
    //    movement = glm::vec3(-1, 0, 0);
    //}
    //else if (facing == RIGHT) {
    //    movement = glm::vec3(1, 0, 0);
    //}

    //// if go out of walking bound, turns the othe way
    //if (position.x >= initialPos.x + walkRadius) {
    //    facing = LEFT;
    //}
    //else if (position.x <= initialPos.x - walkRadius) {
    //    facing = RIGHT;
    //}



}
