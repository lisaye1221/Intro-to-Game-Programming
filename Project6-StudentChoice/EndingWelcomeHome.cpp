#include "EndingWelcomeHome.h"
#define ENDINGCYCLE_WIDTH 33
#define ENDINGCYCLE_HEIGHT 18

using namespace std;

int linesIndex_home = 0;

unsigned int endinghome_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
    56, 57, 34, 35, 34, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
    48, 49, 35, 34, 35, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
    56, 57, 34, 35, 34, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
    48, 49, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
    56, 57, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


vector<vector<string>> ENDINGHOME_LINES = {

    {
        "....",
    },
    {
        "I'm back...?"
    },
    {
        "We're back!"
    },
    { // 3
        "!!",
        "Magenta?",
        "I did it!",
        "I brought you back",
        "Promise me you won't get yourself lost in the woods again"
    },
    { // 4
        "Hehe, I won't, promise",
        ".....",
        "Hey",
        "Thanks for saving me...",
        "I don't really remember what happened",
        "But it must not have been easy..."
    },
    { // 5
        "What's with the sad face?",
        "You would have done the same for me right?",
        "Come on, let's go home!"
    }

};

void EndingWelcomeHome::Initialize() {
    Level::Initialize();
    //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // initialize audio
    //bgm = Mix_LoadMUS("assets/audio/The-Attic-of-Secrets.mp3");
    //Mix_VolumeMusic(MIX_MAX_VOLUME / 7);
    //// Check load
    //if (bgm == NULL) {
    //    std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
    //    assert(false);
    //}
    //// loop the bgm
    //Mix_PlayMusic(bgm, -1);
    popSfx = Mix_LoadWAV("assets/audio/pop.wav");
    Mix_VolumeChunk(popSfx, MIX_MAX_VOLUME / 4);

    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/world.png");
    state.map = new Map(ENDINGCYCLE_WIDTH, ENDINGCYCLE_HEIGHT, endinghome_data, mapTextureID, 1.0f, 8, 8, MapType::GRASS);

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(3, -6.5, 0));
    state.player->animIndices = state.player->animRight;
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // magenta, not active
    textID = Util::LoadTexture("assets/friend.png");
    state.magenta = new NPC(textID, glm::vec3(2.8, -7.5, 0), 0, EntityType::MAGENTA);
    state.magenta->setFacing(RIGHT);
    state.allEntities.push_back(state.magenta);

    // setting up the lines
    lines.emplace_back(ENDINGHOME_LINES[0], "");
    lines.emplace_back(ENDINGHOME_LINES[0], "Magenta");
    lines.emplace_back(ENDINGHOME_LINES[1], "");
    lines.emplace_back(ENDINGHOME_LINES[2], "Magenta");
    lines.emplace_back(ENDINGHOME_LINES[3], "");
    lines.emplace_back(ENDINGHOME_LINES[4], "Magenta");
    lines.emplace_back(ENDINGHOME_LINES[5], "");

}
void EndingWelcomeHome::Update(float deltaTime) {

    // Entity updates
    state.player->Update(deltaTime, state.allEntities, state.map);
    state.magenta->Update(deltaTime, state.player, state.allEntities, state.map);
    for (NPC* enemy : state.enemies) {
        enemy->Update(deltaTime, state.player, state.allEntities, state.map);
    }
    for (Entity* object : state.objects) {
        object->Update(deltaTime, state.allEntities, state.map);
    }
    state.player->resetMovement();
    state.magenta->resetMovement();

    // interaction control
    switch (state.player->interactionType) {
    case InteractionType::MAGENTA:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::SIGN:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NONE:
        break;
    }

    if (startNextLine) {
        state.currText = lines[linesIndex_home];
        state.player->isInteracting = true;
        startNextLine = false;
    }
    if (linesIndex_home == 1 && state.currText.isAtEnd()) {
        walkForward = true;
    }
    else if (linesIndex_home == 3 && state.currText.isAtEnd()) {
        state.player->animIndices = state.player->animDown;
        state.magenta->setFacing(UP);
        startNextLine = true;
        linesIndex_home++;
    }
    else if (linesIndex_home == lines.size() - 1 && state.currText.isAtEnd()) {
        walkHome = true;
    }
    else if (linesIndex_home < lines.size() - 1 && state.currText.isAtEnd()) {
        startNextLine = true;
        linesIndex_home++;
    }

    // both player and magenta walks forward
    if (walkForward) {
        if (state.player->getPosition().x < 7) {
            state.player->setMovement(glm::vec3(1, 0, 0));
            state.magenta->setSpeed(3.5);
        }
        else {
            state.player->setPosition(glm::vec3(7, state.player->getPosition().y, state.player->getPosition().z));
            state.magenta->setPosition(glm::vec3(7, state.magenta->getPosition().y, state.magenta->getPosition().z));
            state.player->resetMovement();
            state.magenta->setSpeed(0);
            walkForward = false;
            linesIndex_home++;
            startNextLine = true;
        }
    }

    if (walkHome) {
        shouldFadeOut = true;
        if (state.player->getPosition().x < 28) {
            state.player->setMovement(glm::vec3(1, 0, 0));
            state.player->animIndices = state.player->animRight;
            state.magenta->setFacing(RIGHT);
            state.magenta->setSpeed(3.5);
        }
        else {
            nextScene = 11;
        }
    }


}
void EndingWelcomeHome::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);

}
void EndingWelcomeHome::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);

}
void EndingWelcomeHome::Interact() {}
