#include "Player.h"

int PLAYER_MAX_LIFE = 3;

Player::Player(GLuint textID, glm::vec3 position, float speed):
    Entity(EntityType::PLAYER, textID, position, speed),jump(false), jumpPower(6.5f) {
    jumpSfx = Mix_LoadWAV("assets/audio/jump.wav");
    Mix_VolumeChunk(jumpSfx, MIX_MAX_VOLUME / 3);
    contactSfx = Mix_LoadWAV("assets/audio/contact.wav");
    Mix_VolumeChunk(contactSfx, MIX_MAX_VOLUME / 3);
    alertSfx = Mix_LoadWAV("assets/audio/egg_crack.wav");
    lives = PLAYER_MAX_LIFE;

}

int Player::getLives() const { return lives; }

void Player::decreaseLife() {
    if (lives > 0) {
        Mix_PlayChannel(-1, alertSfx, 0);
        lives--;
    }
}
void Player::increaseLife() {
    if (lives < PLAYER_MAX_LIFE) {
        lives++;
    }
}
void Player::hitObstacle() {
    // loses a life
    decreaseLife();
    isInvincible = true;
    // recoil from hitting the enemy
    (facing == LEFT) ? position.x++: position.x--;
}
void Player::copyProgress(Player* prevPlayer) {
    lives = prevPlayer->lives;
}

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

    // test if player collide with spike
    // use isInvincible to avoid losing multiple lives, player is safe until player recoils back to a non-spike tile
    if (map->IsSpike(left, &penetration_x, &penetration_y) || map->IsSpike(right, &penetration_x, &penetration_y)) {
        if (!rebirth) {
            Mix_PlayChannel(-1, alertSfx, 0);
            rebirth = true;
        }
        
    }

    // test if player collides with door, is at a door
    if (map->IsDoor(left, &penetration_x, &penetration_y) || map->IsDoor(right, &penetration_x, &penetration_y)) {
        advanceStage = true;
    }

}


void Player::ProcessPlayerInput(SDL_Event& event) {
        movement = glm::vec3(0);

        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_SPACE:
                if (collidedBottom) { 
                    jump = true; 
                    Mix_PlayChannel(-1, jumpSfx, 0);
                }
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
            Mix_PlayChannel(-1, contactSfx, 0);
            // gains a life, heart should then disappear
            increaseLife();
            entity->isActive = false;
            break;
        case EntityType::ENEMY:
            if (!rebirth) {
                Mix_PlayChannel(-1, alertSfx, 0);
                rebirth = true;
            }
            break;
        }
    }
    isInvincible = false;

    Entity::Update(deltaTime, entitySets, map);

    
    
}
