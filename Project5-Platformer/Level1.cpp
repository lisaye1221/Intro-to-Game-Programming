#include "Level1.h"
#define LEVEL1_WIDTH 28
#define LEVEL1_HEIGHT 8

#define Level1_ENEMY_COUNT 2
glm::vec3 INITIAL_POSITION_LEVEL1 = glm::vec3(4, -3, 0);

using namespace std;

unsigned int level1_data[] =
{
	2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 2,
    2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 2,
    2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};

void Level1::Initialize() {
    state.nextScene = -1;
    backgroundMatrix = glm::mat4(1.0f);
    // initialize map
	GLuint mapTextureID = Util::LoadTexture("assets/tileset.png");
	state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, level1_data, mapTextureID, 1.0f, 8, 1);

    backgroundID = Util::LoadTexture("assets/day.png");
    fontTextureID = Util::LoadTexture("assets/font.png");

	
    // initialize audio
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    bgm = Mix_LoadMUS("assets/audio/brave_world.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
    // Check load
    if (bgm == NULL) {
        std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
        assert(false);
    }
    // loop the bgm
    Mix_PlayMusic(bgm, -1);
    initSfx();

     // Initialize Player
    GLuint textID = Util::LoadTexture("assets/egg.png");
    float speed = 2.5;

    state.player = new Player(textID, INITIAL_POSITION_LEVEL1, speed);
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

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
    glm::vec3 initialPos = glm::vec3(14, -4, 0);
    Entity* newHeart = new Entity(EntityType::HEART, textID, initialPos, 0);
    state.allEntities.push_back(newHeart);
    state.items.push_back(newHeart);

    // place enemies
    textID = Util::LoadTexture("assets/bunny.png");
    initialPos = glm::vec3(19, -5, 0);
    NPC* newNPC = new NPC(textID, initialPos, 1.5, BUNNY, 3);
    newNPC->setFacing(LEFT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

    initialPos = glm::vec3(17.5, -2, 0);
    newNPC = new NPC(textID, initialPos, 1.5, BUNNY, 2);
    newNPC->setFacing(RIGHT);
    state.enemies.push_back(newNPC);
    state.allEntities.push_back(newNPC);

}

void Level1::Update(float deltaTime) {

    timeMarker += deltaTime;
    if (int(timeMarker) % 7 == timeToNextSwitch) {
        switchDayAndNight();
        timeToNextSwitch = rand() % 3 + 3;
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
        if (state.player->getLives() > 0) { state.player->setPosition(INITIAL_POSITION_LEVEL1); }
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
        state.nextScene = 2;
    }

}

void Level1::Render(ShaderProgram* program) {

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


    //Util::DrawText(program, fontTextureID, "Player x: " + to_string(state.player->getPosition().x), 0.4, -0.23, glm::vec3(state.player->getPosition().x, state.player->getPosition().y + 3, 0));
    //Util::DrawText(program, fontTextureID, "Player y: " + to_string(state.player->getPosition().y), 0.4, -0.23, glm::vec3(state.player->getPosition().x, state.player->getPosition().y + 1, 0));
    //Util::DrawText(program, fontTextureID, "time: " + to_string(int(timeMarker) % 5), 0.4, -0.23, glm::vec3(state.player->getPosition().x, state.player->getPosition().y + 1, 0));

}