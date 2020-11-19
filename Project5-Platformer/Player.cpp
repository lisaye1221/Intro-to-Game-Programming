#include "Player.h"

int PLAYER_MAX_LIFE = 3;

Player::Player(GLuint textID, glm::vec3 position, float speed):
    Entity(EntityType::PLAYER, textID, position, speed),jump(false), jumpPower(6.5f) {
    lives = PLAYER_MAX_LIFE;

}

int Player::getLives() const { return lives; }

void Player::decreaseLife() {
    if (lives > 0) {
        lives--;
    }
}
void Player::increaseLife() {
    if (lives < PLAYER_MAX_LIFE) {
        lives++;
    }
}

void Player::ProcessPlayerInput(SDL_Event& event) {
        movement = glm::vec3(0);

        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_SPACE:
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
        if (glm::length(movement) > 1.0f) {
            movement = glm::normalize(movement);
        }
	}

void Player::Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map) {
    if (jump) {
        justJumped = true;
        jump = false;
        velocity.y += jumpPower;
    }
    else {
        acceleration = glm::vec3(0, -9.81f, 0);
        ignorePlatform = false;
    }


    // handles game logic when colliding with an entity
    for (Entity * entity : lastCollided) {
        switch (entity->getType()) {
        case EntityType::HEART:
            // gains a life, heart should then disappear
            increaseLife();
            entity->isActive = false;
            break;
        case EntityType::ENEMY:
            // loses a life
            decreaseLife();
            // recoil from hitting the enemy
            (facing == LEFT) ? position.x++ : position.x--;
            break;
        }
    }

    Entity::Update(deltaTime, entitySets, map);

    
    
}
