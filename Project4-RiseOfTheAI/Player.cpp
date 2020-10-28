

#include "Player.h"


Player::Player(GLuint textID, glm::vec3 position, float speed):
    Entity(EntityType::PLAYER, textID, position, speed),jump(false), jumpPower(5.0f) {}

bool Player::onLadder() const {
    for (Entity* entity : lastCollided) {
        if (entity->getType() == EntityType::LADDER) {
            return true;
        }
    }
    return false;
}

void Player::ProcessPlayerInput(SDL_Event event) {
        movement = glm::vec3(0);

        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                // Move the player left
                break;

            case SDLK_RIGHT:
                // Move the player right
                break;

            case SDLK_SPACE:
                // Some sort of action
                if (collidedBottom) { jump = true; }
                break;
            }
            break; // SDL_KEYDOWN
        }
        

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
        else if (keys[SDL_SCANCODE_UP]) {
            if (onLadder()) { 
                movement.y = 1.0f; 
                facing = UP;
                animIndices = animUp;
            }
        }
        else if (keys[SDL_SCANCODE_DOWN]) {
            if (onLadder()) { 
                movement.y = -1.0f; 
                facing = DOWN;
                animIndices = animDown;
            }
        }
        if (glm::length(movement) > 1.0f) {
            movement = glm::normalize(movement);
        }
	}

void Player::Update(float deltaTime, const std::vector<Entity*>& entitySets) {
    if (jump) {
        jump = false;
        velocity.y += jumpPower;
    }
    if (onLadder()) {
        ignorePlatform = true;
        acceleration = glm::vec3(0);
        velocity.y = movement.y * speed;
    }
    else {
        acceleration = glm::vec3(0, -9.81f, 0);
        ignorePlatform = false;
    }
    Entity::Update(deltaTime, entitySets);


}
