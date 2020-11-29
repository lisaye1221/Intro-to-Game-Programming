#include "Player.h"

Player::Player(GLuint textID, glm::vec3 position, float speed):
    Entity(EntityType::PLAYER, textID, position, speed) {
    contactSfx = Mix_LoadWAV("assets/audio/contact.wav");
    Mix_VolumeChunk(contactSfx, MIX_MAX_VOLUME / 3);
    alertSfx = Mix_LoadWAV("assets/audio/egg_crack.wav");


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


void Player::ProcessPlayerInput(SDL_Event& event) {
        movement = glm::vec3(0);
        
        const Uint8* keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_LEFT]) {
            movement.x = -1.0f;
            facing = LEFT;
            animIndices = animLeft;
        }
        else if (keys[SDL_SCANCODE_RIGHT]) {
            movement.x = 1.0f;
            facing = RIGHT;
            animIndices = animRight;
        }
        if (glm::length(movement) > 1.0f) {
            movement = glm::normalize(movement);
        }
	}

void Player::Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map) {

    Entity::Update(deltaTime, entitySets, map);

    
}
