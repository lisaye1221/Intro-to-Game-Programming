#pragma once

#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

#include "Map.h"

#include <algorithm>
#include <vector>

enum class EntityType {PLAYER, NPC, HEART, ENEMY, FRIEND};
enum Direction {LEFT, RIGHT, UP, DOWN};

class Entity {
protected:
    EntityType entityType;
    glm::vec3 position;
    glm::vec3 movement;
    glm::vec3 acceleration;
    glm::vec3 velocity;
    float speed;
    float width = 1;
    float height = 1;
    bool ignorePlatform;
    Direction facing;

    std::vector<Entity*> lastCollided;

    GLuint textureID;
    glm::mat4 modelMatrix;
public:
    int* animRight = NULL;
    int* animLeft = NULL;
    int* animUp = NULL;
    int* animDown = NULL;

    int* animIndices = NULL;
    int animFrames = 0;
    int animIndex = 0;
    float animTime = 0;
    int animCols = 0;
    int animRows = 0;

    bool isActive = true;
    bool collidedTop = false;
    bool collidedBottom = false;
    bool collidedLeft = false;
    bool collidedRight = false;

    Entity(EntityType type, GLuint textID, glm::vec3 position, float speed);
    ~Entity();

    // getters
    EntityType getType() const;
    glm::vec3 getPosition() const;
    glm::vec3 getMovement() const;
    glm::vec3 getVelocity() const;
    float getSpeed() const;
    Direction getFacing() const;

    // setters
    void resetMovement();
    void setPosition(glm::vec3 pos);
    void setSize(float w, float h);
    void setSpeed(float spd);
    void setFacing(Direction direction);

    bool CheckCollision(Entity* other);
    void CheckCollisionsY(Entity* object);
    void CheckCollisionsX(Entity* object);
    void CheckCollisionsX(Map* map);
    void CheckCollisionsY(Map* map);
    virtual void Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map);
    virtual void Render(ShaderProgram* program);
    void DrawSpriteFromTextureAtlas(ShaderProgram* program, GLuint textureID, int index);
};
