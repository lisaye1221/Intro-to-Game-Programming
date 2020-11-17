
#include "NPC.h"


NPC::NPC(GLuint textID, const glm::vec3& pos, float speed, AIType type)
    : Entity(EntityType::NPC, textID, pos, speed), aiType(type) {
    acceleration = glm::vec3(0);
}

AIType NPC::getAIType() const { return aiType; }


void NPC::Update(float deltaTime, Entity* player, const std::vector<Entity*>& entitySets, Map* map) {
    AI(player);
    velocity.y = movement.y * speed;
    animIndices = facing == LEFT ? animLeft : animRight;
    Entity::Update(deltaTime, entitySets, map);
}

void NPC::AI(Entity* player) {

    /*switch (aiType) {
    case RUNNER:
        AIRunner(player);
        break;
    case COPIER:
        AICopier(player);
        break;
    case SLEEPER:
        AISleeper(player);
        break;
    }*/

}
