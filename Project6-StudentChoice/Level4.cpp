#include "Level4.h"
#define LEVEL4_WIDTH 70
#define LEVEL4_HEIGHT 18

int talkedToMagenta_4 = 0;

using namespace std;

int EM = 44; // empty

unsigned int level4_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    51, 52, 52, 52, 52, 54, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    64, 65, 65, 65, 65, 51, 52, 52, 52, 52, 54, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    72, 73, 73, 73, 73, 65, 65, 65, 65, 65, 51, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 0,
    29, 28, 29, 29, 29, 72, 73, 73, 73, 73, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 67, 65, 0,
    28, 29, 28, 29, 29, 29, 29, 29, 29, 29, 72, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 75, 73, 0,
    29, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 30, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 28, 29, 29, 29, 29, 29, 31, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 27, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 31, 29, 28, 25, 29, 29, 29, 29, 29, 29, 29, 29, 26, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 26, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 29, 29, 29, 28, 28, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 0,
    57, 57, 57, 49, 29, 28, 29, 29, 27, 26, 43, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    EM, EM, EM, 56, 57, 57, 57, 57, 57, 57, 43, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

vector<vector<string>> MAGENTA_LINES_LEVEL4 = {
    { // 0
      "Wait",
      "How did you even get here?",
      "Did you hack the game?"
    },
};
vector<vector<string>> LEVEL4_LINES = {
    {
        "(I think I can move on from here)",
        "(But what was that about?)",
        "(No matter, I must move on)"
    },
    {
        "Welcome to the world 4",
        "To get through this world, you must walk straight",
        "Beyond those rocks is the path you must walk",
        "The exit is at the end of the path",
        "Do not look away under ANY circumstance",
        "Or else...",
        "You will die"

    },
    {
        "That was easy right?",
        "The next world is just pass the exit on the right",
        "Congrats, the end is near"
    }
};


void Level4::Initialize() {
    Level::Initialize();
    viewScrolls = true;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // initialize audio
    bgm = Mix_LoadMUS("assets/audio/Chilly-Whispers.wav");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 7);
    // Check load
    if (bgm == NULL) {
        std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
        assert(false);
    }
    // loop the bgm
    Mix_PlayMusic(bgm, -1);
    popSfx = Mix_LoadWAV("assets/audio/pop.wav");
    Mix_VolumeChunk(popSfx, MIX_MAX_VOLUME / 4);

    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/cave.png");
    state.map = new Map(LEVEL4_WIDTH, LEVEL4_HEIGHT, level4_data, mapTextureID, 1.0f, 8, 16, CAVE);
    nextStageAppear = false;

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(1, -8.5, 0));
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/magenta.png");
    state.magenta = new NPC(textID, glm::vec3(25, -6, 0), 0, EntityType::MAGENTA);
    state.magenta->animIndices = NULL; // this magenta will not animate
    state.allEntities.push_back(state.magenta);
    state.magenta->lines = MAGENTA_LINES_LEVEL4;

    // left sign
    textID = Util::LoadTexture("assets/sign.png");
    Entity* sign = new Entity(EntityType::SIGN, textID, glm::vec3(7, -5, 0), 0);
    sign->lines.push_back(LEVEL4_LINES[1]);
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    // right sign
    sign = new Entity(EntityType::SIGN, textID, glm::vec3(64, -6, 0), 0);
    sign->lines.push_back(LEVEL4_LINES[2]); 
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    textID = Util::LoadTexture("assets/skeleton_red.png");
    NPC* enemy = new NPC(textID, glm::vec3(50, -1, 0), 3.0, EntityType::FAKEMONSTER);
    enemy->isActive = false; // do not appear at first
    state.allEntities.push_back(enemy);
    state.enemies.push_back(enemy);

    for (Entity* entity : state.allEntities) {
        entity->rightBorderBounded = false;
    }

}
void Level4::Update(float deltaTime) {

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
            talkedToMagenta_4++;
        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
            // nextScene = 4;
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::SIGN:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NONE:
        state.player->isInteracting = false;
        break;
    }

    

}
void Level4::Render(ShaderProgram* program) {
    Level::Render(program);


    if (state.player->getPosition().x > 52.5) {
        Util::DrawText(program, fontTextureID, "Dead:" + to_string(state.player->isDead), 0.8, -0.2, glm::vec3(56.5, 2.5, 0));
        Util::DisplayText(program, fontTextureID, state.currText, 37.5);
    }
    else if (state.player->getPosition().x > 16) {
        Util::DrawText(program, fontTextureID, "Dead:" + to_string(state.player->isDead), 0.8, -0.2, glm::vec3(state.player->getPosition().x + 4, 2.5, 0));
        Util::DisplayText(program, fontTextureID, state.currText, state.player->getPosition().x - 15);
    }
    else {
        Util::DrawText(program, fontTextureID, "Dead:" + to_string(state.player->isDead), 0.8, -0.2, glm::vec3(20, 2.5, 0));
        Util::DisplayText(program, fontTextureID, state.currText);

    }

}
void Level4::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);
}

void Level4::Interact() {

    state.player->isInteracting = true;

    switch (state.player->onWhat) {
    case InteractionType::MAGENTA:
        state.player->interactionType = InteractionType::MAGENTA;
        state.currText = Text(state.magenta->lines[0], "Magenta");
        break;
    case InteractionType::NEXTSTAGE:
        state.player->interactionType = InteractionType::NEXTSTAGE;
        state.currText = Text(LEVEL4_LINES[0], "");
        break;
    case InteractionType::SIGN:
        state.player->interactionType = InteractionType::SIGN;
        if (state.player->getPosition().x < 20) { // left sign
            state.currText = Text(state.objects[0]->lines[0], "");
        }
        else {
            state.currText = Text(state.objects[1]->lines[0], "");
        }
        break;
    }



}