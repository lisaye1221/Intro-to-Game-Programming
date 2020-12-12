
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
    else if (type == EntityType::MONSTER) {
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
    else {
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

void NPC::setType(EntityType type) { entityType = type; }

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

    // moves left or right depending on where it's facing
    if (!shouldStop) {
        if (facing == LEFT) {
            movement = glm::vec3(-1, 0, 0);
        }
        else if (facing == RIGHT) {
            movement = glm::vec3(1, 0, 0);
        }
        else if (facing == UP) {
            movement = glm::vec3(0, 1, 0);

        }
        else if (facing == DOWN) {
            movement = glm::vec3(0, -1, 0);
        }
    }
    else {
        movement = glm::vec3(0, 0, 0);
    }
    

    switch (entityType) {
    case EntityType::MONSTER:
        AI_MONSTER(player);
        break;
    case EntityType::CHASER:
        AI_CHASER(player);
        break;
    case EntityType::FAKEMONSTER:
        AI_FAKEMONSTER(player);
    case EntityType::MAGENTA_B:
        AI_MAGENTA_B(player);
        break;
    }



}

// monsters in level 3
void NPC::AI_MONSTER(Entity* player) {    

    if (goLeftOrRight) {
        if (position.x < 1.0f) { facing = RIGHT; }
        if (position.x > 31.0f) { facing = LEFT; }
    }
    else {
        if (position.y > -1.5f) { facing = DOWN; }
        if (position.y < -15.0f) { facing = UP; }
    }

}

void NPC::AI_CHASER(Entity* player) {
    float x = player->getPosition().x;
    float y = player->getPosition().y;

    if (abs(x - position.x) > 0.3) {
        facing = x > position.x ? RIGHT : LEFT;
    }
    else {
        facing = y > position.y ? UP : DOWN;
    }


}

void NPC::AI_FAKEMONSTER(Entity* player) {
    if (facing != LEFT) { facing = LEFT; }
}

void NPC::CheckCollisionsX(Map* map) {
    glm::vec3 left = glm::vec3(position.x - (width / 2), position.y, position.z);
    glm::vec3 right = glm::vec3(position.x + (width / 2), position.y, position.z);
    float penetration_x = 0;
    float penetration_y = 0;
    if (map->IsSolid(left, &penetration_x, &penetration_y) && velocity.x < 0) {
        position.x += penetration_x;
        velocity.x = 0;
        collidedLeft = true;
 
    }
    if (map->IsSolid(right, &penetration_x, &penetration_y) && velocity.x > 0) {
        position.x -= penetration_x;
        velocity.x = 0;
        collidedRight = true;

    }

    

}

void NPC::AI_MAGENTA_B(Entity* player) {
    facing = DOWN;
    if (didCollideWith(player)) {
        player->setPosition(glm::vec3(player->getPosition().x, player->getPosition().y - 1, player->getPosition().z));
    }

}

void NPC::CheckCollisionsY(Map* map)
{
    // Probes for tiles
    glm::vec3 top = glm::vec3(position.x, position.y + (height / 2), position.z);
    glm::vec3 top_left = glm::vec3(position.x - (width / 2), position.y + (height / 2), position.z);
    glm::vec3 top_right = glm::vec3(position.x + (width / 2), position.y + (height / 2), position.z);
    glm::vec3 bottom = glm::vec3(position.x, position.y - (height / 2), position.z);
    glm::vec3 bottom_left = glm::vec3(position.x - (width / 2), position.y - (height / 2), position.z);
    glm::vec3 bottom_right = glm::vec3(position.x + (width / 2), position.y - (height / 2), position.z);
    float penetration_x = 0;
    float penetration_y = 0;
    if (map->IsSolid(top, &penetration_x, &penetration_y) && velocity.y > 0) {
        position.y -= penetration_y;
        velocity.y = 0;
        collidedTop = true;
    }
    else if (map->IsSolid(top_left, &penetration_x, &penetration_y) && velocity.y > 0) {
        position.y -= penetration_y;
        velocity.y = 0;
        collidedTop = true;
    }
    else if (map->IsSolid(top_right, &penetration_x, &penetration_y) && velocity.y > 0) {
        position.y -= penetration_y;
        velocity.y = 0;
        collidedTop = true;
    }
    if (map->IsSolid(bottom, &penetration_x, &penetration_y) && velocity.y < 0) {
        position.y += penetration_y;
        velocity.y = 0;
        collidedBottom = true;
    }
    else if (map->IsSolid(bottom_left, &penetration_x, &penetration_y) && velocity.y < 0) {
        position.y += penetration_y;
        velocity.y = 0;
        collidedBottom = true;
    }
    else if (map->IsSolid(bottom_right, &penetration_x, &penetration_y) && velocity.y < 0) {
        position.y += penetration_y;
        velocity.y = 0;
        collidedBottom = true;
    }

}
