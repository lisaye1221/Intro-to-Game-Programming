#include "Level2.h"
#define LEVEL2_WIDTH 30
#define LEVEL2_HEIGHT 8
#define Level2_ENEMY_COUNT 2
glm::vec3 INITIAL_POSITION_LEVEL2 = glm::vec3(2, -3, 0);

unsigned int level2_data[] =
{
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 2,
    2, 2, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 5, 0, 0, 7, 2, 2,
    2, 2, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2
};

void Level2::Initialize() {
    state.nextScene = -1;
    backgroundMatrix = glm::mat4(1.0f);
    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/tileset.png");
    state.map = new Map(LEVEL2_WIDTH, LEVEL2_HEIGHT, level2_data, mapTextureID, 1.0f, 8, 1);

    backgroundID = Util::LoadTexture("assets/day.png");
    fontTextureID = Util::LoadTexture("assets/font.png");
    initSfx();

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/egg.png");

    state.player = new Player(textID, INITIAL_POSITION_LEVEL2, 2.5);
    state.allEntities.push_back(state.player);

    state.player->animRight = new int[5]{ 0, 1, 2, 3, 4 };
    state.player->animLeft = new int[5]{ 5, 6, 7, 8, 9 };


    state.player->animIndices = state.player->animRight;
    state.player->animFrames = 5;
    state.player->animIndex = 0;
    state.player->animTime = 0;
    state.player->animCols = 10;
    state.player->animRows = 1;

    // place a heart 
    textID = Util::LoadTexture("assets/full_heart.png");
    glm::vec3 initialPos = glm::vec3(18, -1, 0);
    Entity* newHeart = new Entity(EntityType::HEART, textID, initialPos, 0);
    state.allEntities.push_back(newHeart);
    state.items.push_back(newHeart);

    // place enemies
    textID = Util::LoadTexture("assets/bunny.png");
    initialPos = glm::vec3(15, -5, 0);
    NPC* newNPC = new NPC(textID, initialPos, 1.5, BUNNY, 4);
    newNPC->setFacing(LEFT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    initialPos = glm::vec3(17, -1, 0);
    newNPC = new NPC(textID, initialPos, 1.5, BUNNY, 1.5);
    newNPC->setFacing(LEFT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    textID = Util::LoadTexture("assets/fish.png");
    initialPos = glm::vec3(12, -3, 0);
    newNPC = new NPC(textID, initialPos, 1.5, FISH, 2);
    newNPC->setFacing(RIGHT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    

}

void Level2::Update(float deltaTime) {

    timeMarker += deltaTime;
    if (int(timeMarker) % 10 == timeToNextSwitch) {
        switchDayAndNight();
        timeToNextSwitch = rand() % 3 + 6;
        timeMarker = 0;
    }

    state.player->Update(deltaTime, state.allEntities, state.map);

    // update npc's
    for (NPC* npc : state.enemies) {
        npc->Update(deltaTime, state.player, state.allEntities, state.map);
    }
    // update items
    for (Entity* item : state.items) {
        item->Update(deltaTime, {}, state.map);
    }

    backgroundMatrix = glm::mat4(1.0f);
    if (state.player->getPosition().x > 5) {
        backgroundMatrix = glm::translate(backgroundMatrix, glm::vec3(state.player->getPosition().x, 0, 0));

    }
    else {
        backgroundMatrix = glm::translate(backgroundMatrix, glm::vec3(1, 0, 0));

    }

    // when player falls in the pit
    // loses one life, sends player back to start of level
    if (state.player->getPosition().y < -10) {
        state.player->decreaseLife();
        if (state.player->getLives() > 0) { state.player->setPosition(INITIAL_POSITION_LEVEL2); }

    }
    if (state.player->rebirth) {
        state.player->clearLastCollided();
        state.player->decreaseLife();
        if (state.player->getLives() > 0) { state.player->setPosition(INITIAL_POSITION_LEVEL2); }
        state.player->rebirth = false;
    }

    // check if player is dead
    if (state.player->getLives() == 0) {
        state.gameLost = true;
        gameLose();
    }

    // if player touches a door, transition to next level
    if (state.player->advanceStage) {
        Mix_VolumeChunk(nextLevelSfx, MIX_MAX_VOLUME / 4);

        Mix_PlayChannel(-1, nextLevelSfx, 0);
        state.nextScene = 3;
    }
}

void Level2::Render(ShaderProgram* program) {

    float vertices[] = { -9.0, -8.75, 9.0, -8.75, 9.0, 8.75, -9.0, -8.75, 9.0, 8.75, -9.0, 8.75 };
    float texCoords[] = { 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0 };
    glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program->positionAttribute);
    glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords);
    glEnableVertexAttribArray(program->texCoordAttribute);

    // draw the background
    program->SetModelMatrix(backgroundMatrix);
    glBindTexture(GL_TEXTURE_2D, backgroundID);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(program->positionAttribute);
    glDisableVertexAttribArray(program->texCoordAttribute);

    state.map->Render(program);
    state.player->Render(program);

    // render enemies
    for (NPC* npc : state.enemies) {
        npc->Render(program);
    }

    // render items
    for (Entity* item : state.items) {
        item->Render(program);
    }

    // draw the relevant texts
    displayText(program, fontTextureID);

    //Util::DrawText(program, fontTextureID, "Player x: " + std::to_string(state.player->getPosition().x), 0.4, -0.23, glm::vec3(state.player->getPosition().x, state.player->getPosition().y + 3, 0));
    //Util::DrawText(program, fontTextureID, "Player y: " + std::to_string(state.player->getPosition().y), 0.4, -0.23, glm::vec3(state.player->getPosition().x, state.player->getPosition().y + 1, 0));

}