#include "Player.h"

Player::Player(GLuint textID, glm::vec3 position):
    Entity(EntityType::PLAYER, textID, position, speed) {
    speed = 3.0f;


}

//void Player::copyProgress(Player* prevPlayer) {
//   
//}

void Player::CheckCollisionsX(Map* map) {
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

    // test if player collides with door, is at a door
    if (map->IsDoor(left, &penetration_x, &penetration_y) || map->IsDoor(right, &penetration_x, &penetration_y)) {
    }

}

void Player::CheckCollisionsY(Map* map)
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




void Player::ProcessPlayerInput(SDL_Event& event) {
        movement = glm::vec3(0);
        
        const Uint8* keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_A]) { // left
            movement.x = -1.0f;
            facing = LEFT;
            animIndices = animLeft;
        }
        else if (keys[SDL_SCANCODE_D]) { // right
            movement.x = 1.0f;
            facing = RIGHT;
            animIndices = animRight;
        }
        else if (keys[SDL_SCANCODE_W]) { // up
            movement.y = 1.0f;
            facing = UP;
            animIndices = animUp;
        }
        else if ((keys[SDL_SCANCODE_S])) { // down
            movement.y = -1.0f;
            facing = DOWN;
            animIndices = animDown;
        }
        if (glm::length(movement) > 1.0f) {
            movement = glm::normalize(movement);
        }
	}

void Player::Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map) {

    Entity::Update(deltaTime, entitySets, map);

    
}
