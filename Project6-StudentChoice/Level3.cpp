#include "Level3.h"
#define LEVEL3_WIDTH 33
#define LEVEL3_HEIGHT 18

int talkedToMagenta_3 = 0;
bool talkedBefore = false;

using namespace std;

int SA = 48; // sand
int FL = 67; // flower

unsigned int level3_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 48, 48, 48, 48, 48, 48, 60, 59, 59, 60, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 60, 59, 59, 60, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 60, 59, 59, 60, 48, 48, 60, 62, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 60, 60, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 60, 48, 49, 60, 48, 48, 63, 61, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 61, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, SA, SA, SA, 48, 48,
    48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, SA, SA, SA, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, SA, SA, SA, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 62, 59, 48, 48, 48, 48, 48, 48, 48, 48, 61, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 60, 55, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 60, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 62, 48, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 61, 62, 48, 48,
    48, 48, 63, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 59, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
unsigned int level3_clear_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 48, 48, 48, 48, 48, 48, 60, 59, 59, 60, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 60, 59, 59, 60, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 60, 59, 59, 60, 48, 48, 60, 62, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 60, 60, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 60, 48, 49, 60, 48, 48, 63, 61, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 61, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, FL, FL, FL, 48, 48,
    48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, FL, FL, FL, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, FL, FL, FL, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 62, 59, 48, 48, 48, 48, 48, 48, 48, 48, 61, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 63, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 60, 55, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 60, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 62, 48, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 61, 62, 48, 48,
    48, 48, 63, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 59, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 60, 59, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
vector<vector<string>> MAGENTA_LINES_LEVEL3 = {
    { // 0
      "This place seems dangerous",
      "Seems like monster can come out any second",
      "Hmmmm... You don't seem like you can fight",
      "So maybe you should just run away from the monsters",
      "Me?",
      "Haha you don't have to worry about me",
      "They won't attack me",
      "Why?",
      "...",
      "I wonder why",
      "Anyways, there's a sign there!",
      "Why don't you go read it?"
    },
    { // 1
        "There they come!",
        "What? I can't really fight either...",
        "Best thing to do now is just avoid them!"
    },
    { // 2
       "Why are you talking to me now",
       "Don't let me distract you",
       "I'll be fine"
    },
    { // 3
        "It's not the time to talk now",
        "I didn't came with you to see you die"
    },
    { // 4
        "Oh, you're safe",
        "Didn't need my help for this one did you?",
        "Are you getting use to these things?",
        "You don't even need to ask me anymore",
        "Oh well, we can move on now"
    },
    { //5
        "Seems like you survived the attack",
        "I'm glad you're safe",
        "Look! Over there, the flower patch",
        "We can move on now!"
    }
};
vector<vector<string>> LEVEL3_LINES = {
    {
        "To leave this world, you must endure 30 seconds of attack",
        "What will lie ahead...",
        "Freedom or death?"
    },
    {
        "You have passed the test",
        "You may now proceed"
    },
    {
        "Do you fear death?"
    },
    {
        "In this world...",
        "How are you choosing who to trust?",
        "Proceed with caution"
    },
    {"(I think I can move on from here)"}
};


void Level3::Initialize() {
    Level::Initialize();
    worldNum = 3;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // initialize audio
    bgm = Mix_LoadMUS("assets/audio/Lost-in-a-Labyrinth.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 10);
    // Check load
    if (bgm == NULL) {
        std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
        assert(false);
    }
    // loop the bgm
    Mix_PlayMusic(bgm, -1);
    popSfx = Mix_LoadWAV("assets/audio/pop.wav");
    stabSfx = Mix_LoadWAV("assets/audio/stab.wav");
    Mix_VolumeChunk(popSfx, MIX_MAX_VOLUME / 4);
    Mix_VolumeChunk(stabSfx, MIX_MAX_VOLUME / 4);

    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/world1.png");
    state.map = new Map(LEVEL3_WIDTH, LEVEL3_HEIGHT, level3_data, mapTextureID, 1.0f, 8, 16, WORLD);
    nextStageAppear = false;

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(1, -2, 0));
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/magenta.png");
    state.magenta = new NPC(textID, glm::vec3(5, -1.5, 0), 0, EntityType::MAGENTA);
    state.allEntities.push_back(state.magenta);
    state.magenta->lines = MAGENTA_LINES_LEVEL3;

    // left sign
    textID = Util::LoadTexture("assets/sign_desert.png");
    Entity* sign = new Entity(EntityType::SIGN, textID, glm::vec3(8.5, -4, 0), 0);
    sign->lines.push_back(LEVEL3_LINES[0]);
    sign->lines.push_back(LEVEL3_LINES[1]);
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    // right sign
    sign = new Entity(EntityType::SIGN, textID, glm::vec3(27, -5, 0), 0);
    sign->lines.push_back(LEVEL3_LINES[2]); // this line will show at first
    sign->lines.push_back(LEVEL3_LINES[3]); // this line will show after surviving the attack
    sign->isActive = false;
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    int monsterCount = 8; 
    textID = Util::LoadTexture("assets/skeleton.png");
    NPC* enemy;
    for (int i = 0; i < monsterCount; i++) {
        float randSpd = rand() % 3 + 5;
        enemy = new NPC(textID, glm::vec3(31.5, 0, 0), randSpd, EntityType::MONSTER);
        enemy->isActive = false; // do not appear at first
        state.allEntities.push_back(enemy);
        state.enemies.push_back(enemy);

    }
    // set each of their positions, speed, direction
    state.enemies[0]->setPosition(glm::vec3(1.5, -5, 0));
    state.enemies[1]->setPosition(glm::vec3(31, -8, 0));
    state.enemies[2]->setPosition(glm::vec3(16, -1, 0));
    state.enemies[3]->setPosition(glm::vec3(6, -15, 0));
    state.enemies[4]->setPosition(glm::vec3(20, -15, 0));
    state.enemies[5]->setPosition(glm::vec3(25, -1, 0));
    state.enemies[6]->setPosition(glm::vec3(1.5, -10.5, 0));
    state.enemies[7]->setPosition(glm::vec3(11.5, -15, 0));
    state.enemies[0]->setFacing(RIGHT);
    state.enemies[1]->setFacing(LEFT);
    state.enemies[2]->setFacing(DOWN);
    state.enemies[3]->setFacing(UP);
    state.enemies[4]->setFacing(UP);
    state.enemies[5]->setFacing(DOWN);
    state.enemies[6]->setFacing(LEFT);
    state.enemies[7]->setFacing(UP);
    state.enemies[0]->goLeftOrRight = true;
    state.enemies[1]->goLeftOrRight = true;
    state.enemies[2]->goLeftOrRight = false;
    state.enemies[3]->goLeftOrRight = false;
    state.enemies[4]->goLeftOrRight = false;
    state.enemies[5]->goLeftOrRight = false;
    state.enemies[6]->goLeftOrRight = true;
    state.enemies[7]->goLeftOrRight = false;
    textID = Util::LoadTexture("assets/skeleton_red.png");
    enemy = new NPC(textID, glm::vec3(31, -1, 0), 3.0, EntityType::CHASER);
    enemy->isActive = false; // do not appear at first
    state.allEntities.push_back(enemy);
    state.enemies.push_back(enemy);

}
void Level3::Update(float deltaTime) {

    // Entity updates
    state.player->Update(deltaTime, state.allEntities, state.map);
    state.magenta->Update(deltaTime, state.player, state.allEntities, state.map);
    for (NPC* enemy : state.enemies) {
        enemy->Update(deltaTime, state.player, state.allEntities, state.map);
    }
    for (Entity* object : state.objects) {
        object->Update(deltaTime, state.allEntities, state.map);
    }

    // interaction control
    switch (state.player->interactionType) {
    case InteractionType::MAGENTA:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
            state.player->talkedToMangeta();
            talkedToMagenta_3++;
        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
            if (state.player->isDead) {
                nextScene = 7; // bad end-death
            }
            else {
                nextScene = 4;
                
            }
        }
        break;
    case InteractionType::SIGN:
        if (state.currText.isEnd) {
            if (!attackStart && talkedToMagenta_3 > 1) { talkedToMagenta_3 = 1; }
            attackStart = true;
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NONE:
        state.player->isInteracting = false;
        break;
    }

    // other logic control
    if (!state.player->isInteracting && attackStart) { 
        countdownTime -= deltaTime; 
        if (countdownTime < 0) { countdownTime = 0; }
    }
    // show flower patch when attack is done
    if (attackEnd && !nextStageAppear) { 
        state.objects[1]->isActive = true;
        state.map->updateMap(level3_clear_data);
        Mix_PlayChannel(-1, popSfx, 0);
        nextStageAppear = true;
    }
    if (countdownTime <= 0) { 
        if (!attackEnd) { // do this only once
            // despawn all enemies
            for (NPC* enemy : state.enemies) {
                enemy->isActive = false;
            }
        }
        attackEnd = true;
    }

    // spawn monster logic
    if (attackStart && !attackEnd) {
        if (countdownTime < 30 && !state.enemies[0]->isActive) {
            state.enemies[0]->isActive = true;
        }
        if (countdownTime < 30 && !state.enemies[1]->isActive) {
            state.enemies[1]->isActive = true;

        }
        if (countdownTime <= 26 && !state.enemies[2]->isActive) {
            state.enemies[2]->isActive = true;

        }
        if (countdownTime <= 22 && !state.enemies[3]->isActive) {
            state.enemies[3]->isActive = true;

        }
        if (countdownTime <= 20 && !state.enemies[8]->isActive) {
            state.enemies[8]->isActive = true;
        }
        if (countdownTime <= 18 && !state.enemies[4]->isActive) {
            state.enemies[4]->isActive = true;

        }
        if (countdownTime <= 15 && !state.enemies[5]->isActive) {
            state.enemies[5]->isActive = true;
        }
        if (countdownTime <= 12 && !state.enemies[6]->isActive) {
            state.enemies[6]->isActive = true;
        }
        if (countdownTime <= 9 && !state.enemies[7]->isActive) {
            state.enemies[7]->isActive = true;
        }
    }

    // pause monsters when interacting
    if (state.player->isInteracting) {
        for (NPC* npc : state.enemies) {
            npc->shouldStop = true;
        }
    }
    else {
        for (NPC* npc : state.enemies) {
            npc->shouldStop = false;
        }
    }

    // magenta animation
    if (attackEnd) {
        if (state.magenta->getPosition().x < 24.5) {
            state.magenta->setFacing(RIGHT);
            state.magenta->setSpeed(4.5);
        }
        else if (state.magenta->getPosition().y > -5) {
            state.magenta->setFacing(DOWN);
        }
        else {
            state.magenta->setFacing(DOWN);
            state.magenta->setSpeed(0);
        }
    }

    // check if player is dead
    if (state.player->isDead) {
        state.currText = Text({"Ugh"}, "");
        if (!state.player->isInteracting) {
            Mix_PlayChannel(-1, stabSfx, 0);
            state.player->isInteracting = true;
        }
        state.player->interactionType = InteractionType::NEXTSTAGE;
        
    }

}
void Level3::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);
    // Util::DrawText(program, fontTextureID, "Dead:"+to_string(state.player->isDead), 0.8, -0.2, glm::vec3(20, 2.5, 0));
    Util::DrawText(program, fontTextureID, "Time: " + to_string(int(countdownTime)), 0.8, -0.2, glm::vec3(13, 1, 0));
}
void Level3::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);
}

void Level3::Interact() {

    state.player->isInteracting = true;

    switch (state.player->onWhat) {
    case InteractionType::MAGENTA:
        state.player->interactionType = InteractionType::MAGENTA;
        if (attackEnd) {
            state.currText = talkedBefore ? Text(state.magenta->lines[5], "Magenta") : Text(state.magenta->lines[4], "Magenta");
        }
        else if (talkedToMagenta_3 == 0 && !attackStart) {
            state.currText = Text(state.magenta->lines[0], "Magenta");
            talkedBefore = true;
        }
        else if(attackStart){
            if (talkedToMagenta_3 > 3 || talkedToMagenta_3 == 0) { talkedToMagenta_3 = 1; }
            talkedBefore = true;
            state.currText = Text(state.magenta->lines[talkedToMagenta_3], "Magenta");
        }
        break;
    case InteractionType::NEXTSTAGE:
        state.player->interactionType = InteractionType::NEXTSTAGE;
        state.currText = Text(LEVEL3_LINES[4], "");
        break;
    case InteractionType::SIGN:
        state.player->interactionType = InteractionType::SIGN;
        Entity* sign;
        if (state.player->getPosition().x < 10) { // the left sign
            sign = state.objects[0];
        }
        else { // the leff sign
            sign = state.objects[1];
        }
        state.currText = Text(sign->lines[attackEnd], "");
        break;
    }



}