#include "EndingSacrifice.h"
#define ENDINGCYCLE_WIDTH 33
#define ENDINGCYCLE_HEIGHT 18

using namespace std;

int linesIndex_sacrifice = 0;

unsigned int endingsacrifice_data[] =
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


vector<vector<string>> ENDINGSACRIFICE_LINES = {

    {
        "....",
    },
    {
        "I'm back!",
        "What happened inside?",
        "I don't recall anything",
        "My memories really doesn't carry over does it..."
    },
    {
        "....",
        "Wait",
        "Where is she?",
        "No! Not again",
        "I failed again",
        "....",
        "I need to go back"
    },
    {
        "This time...",
        "I will bring you back",
        "Wait for me"
    }

};

void EndingSacrifice::Initialize() {
    Level::Initialize();
    //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/world.png");
    state.map = new Map(ENDINGCYCLE_WIDTH, ENDINGCYCLE_HEIGHT, endingsacrifice_data, mapTextureID, 1.0f, 8, 8, MapType::GRASS);

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(3, -7.5, 0));
    state.player->animIndices = state.player->animRight;
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // magenta, not active
    textID = Util::LoadTexture("assets/magenta.png");
    state.magenta = new NPC(textID, glm::vec3(16, -6.5, 0), 0, EntityType::MAGENTA);
    state.magenta->isActive = false;

    // setting up the lines
    lines.emplace_back(ENDINGSACRIFICE_LINES[0], "");
    lines.emplace_back(ENDINGSACRIFICE_LINES[1], "");
    lines.emplace_back(ENDINGSACRIFICE_LINES[2], "");
    lines.emplace_back(ENDINGSACRIFICE_LINES[3], "");

}
void EndingSacrifice::Update(float deltaTime) {

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
            if (shouldDisplayEnding) {
                nextScene = 10;
            }

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
        state.currText = lines[linesIndex_sacrifice];
        state.player->isInteracting = true;
        startNextLine = false;
    }
    if (linesIndex_sacrifice == 0 && state.currText.isAtEnd()) {
        // player walks ahead a bit
        playerWalkForward = true;
    }
    else if (linesIndex_sacrifice == 1 && state.currText.isAtEnd()) {
        state.player->animIndices = state.player->animLeft;
        linesIndex_sacrifice++;
        startNextLine = true;
    }
    else if (linesIndex_sacrifice == 2 && state.currText.isAtEnd()) {
        // player walks back to flower
        playerWalkBack = true;
    }
    else if (linesIndex_sacrifice == lines.size() - 1 && state.currText.isAtEnd()) {
        // checks if we're done
        nextScene = 10;
    }

    if (playerWalkForward) {
        if (state.player->getPosition().x < 7) {
            state.player->setMovement(glm::vec3(1, 0, 0));
        }
        else {
            state.player->setPosition(glm::vec3(7, state.player->getPosition().y, state.player->getPosition().z));
            state.player->resetMovement();
            playerWalkForward = false;
            linesIndex_sacrifice++;
            startNextLine = true;
        }
    }

    if (playerWalkBack) {
        if (state.player->getPosition().x > 3) {
            state.player->setMovement(glm::vec3(-1, 0, 0));
        }
        else {
            state.player->setPosition(glm::vec3(3, state.player->getPosition().y, state.player->getPosition().z));
            state.player->resetMovement();
            playerWalkBack = false;
            linesIndex_sacrifice++;
            startNextLine = true;
        }
    }

}
void EndingSacrifice::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);

}
void EndingSacrifice::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);

}

void EndingSacrifice::Interact() {}