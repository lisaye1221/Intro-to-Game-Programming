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

#include <vector>

enum class EntityType {PLAYER, PLATFORM, LADDER, ENEMY};

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

    // getters
    EntityType getType()const { return entityType; }
    glm::vec3 getPosition() const { return position; }
    glm::vec3 getMovement() const { return movement; }
    glm::vec3 getVelocity() const { return velocity; }
    int getSpeed() const { return speed; }

    // setters
    void resetMovement() { movement = glm::vec3(0); }
    void setSize(float w, float h) {
        width = w;
        height = h;
    }
    void setSpeed(float spd) {
        speed = spd;
    }

    bool CheckCollision(Entity* other);
    void CheckCollisionsY(Entity* objects, int objectCount);
    void CheckCollisionsX(Entity* objects, int objectCount);
    virtual void Update(float deltaTime, const std::vector<std::pair<Entity*, int>>& entitySets);
    void Render(ShaderProgram* program);
    void DrawSpriteFromTextureAtlas(ShaderProgram* program, GLuint textureID, int index);
};
