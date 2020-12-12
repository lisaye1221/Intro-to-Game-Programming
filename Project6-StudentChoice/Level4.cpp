#include "Level4.h"
#define LEVEL4_WIDTH 70
#define LEVEL4_HEIGHT 18

int talkedToMagenta_4 = 0;

using namespace std;

unsigned int EM = 44; // empty

unsigned int level4_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    51, 52, 52, 52, 52, 54, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    64, 65, 65, 65, 65, 51, 52, 52, 52, 52, 54, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, EM, 0,
    72, 73, 73, 73, 73, 65, 65, 65, 65, 65, 51, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 0,
    29, 28, 29, 29, 29, 72, 73, 73, 73, 73, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 67, 65, 0,
    28, 29, 28, 29, 29, 29, 29, 29, 29, 29, 72, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 73, 75, 73, 0,
    29, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 30, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 31, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 28, 29, 29, 29, 29, 29, 31, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 31, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 27, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 0,
    29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 31, 29, 28, 25, 29, 29, 29, 29, 29, 29, 29, 29, 26, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 26, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 29, 28, 29, 29, 29, 29, 0,
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
        "Do not look away under any circumstance",
        "And that is ANY circumstance",
        "Or else...",
        "You will die"

    },
    {
        "This is the end of the path",
        "That was easy right?",
        "The next world is just pass the exit on the right",
        "Congrats, the end is near"
    },
    {
        "(Something tells me I better go read the sign over there first...)"
    },
    {
        "?",
        "(Something is blocking me from going back)"
    }
};


void Level4::Initialize() {
    Level::Initialize();
    worldNum = 4;
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
    state.magenta->animFrames = 0;
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
    sign->isActive = false;
    sign->lines.push_back(LEVEL4_LINES[2]); 
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    // fake things to trick player
    textID = Util::LoadTexture("assets/sign_fake.png");
    Entity* object = new Entity(EntityType::OBJECT, textID, glm::vec3(38, -6, 0), 0);
    state.objects.push_back(object);
    state.allEntities.push_back(object);

    textID = Util::LoadTexture("assets/chest_inanimate.png");
    object = new Entity(EntityType::OBJECT, textID, glm::vec3(59, -6, 0), 0);
    state.objects.push_back(object);
    state.allEntities.push_back(object);

    // fake monsters
    textID = Util::LoadTexture("assets/skeleton_red.png");
    NPC* enemy = new NPC(textID, glm::vec3(55, -6.5, 0), 8.7, EntityType::FAKEMONSTER);
    enemy->isActive = false; // do not appear at first
    state.allEntities.push_back(enemy);
    state.enemies.push_back(enemy);

    enemy = new NPC(textID, glm::vec3(60, -8.0, 0), 9.1, EntityType::FAKEMONSTER);
    enemy->isActive = false; // do not appear at first
    state.allEntities.push_back(enemy);
    state.enemies.push_back(enemy);

    enemy = new NPC(textID, glm::vec3(55, -9.5, 0), 8.8, EntityType::FAKEMONSTER);
    enemy->isActive = false; // do not appear at first
    state.allEntities.push_back(enemy);
    state.enemies.push_back(enemy);

    textID = Util::LoadTexture("assets/scary.png");
    enemy = new NPC(textID, glm::vec3(60, -8.0, 0), 11.0, EntityType::FAKEMONSTER);
    enemy->animIndices = NULL; 
    enemy->animFrames = 0;
    enemy->animCols = 1;
    enemy->animRows = 1;
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
            nextScene = 5;
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::SIGN:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
            if (!readSign) {
                state.player->setPosition(glm::vec3(state.player->getPosition().x - 1, state.player->getPosition().y, state.player->getPosition().z));
            }
        }
        break;
    case InteractionType::NONE:
        state.player->isInteracting = false;
        break;
    }

    // prevents player from moving forward if didn't read sign
    if (state.player->getPosition().x > 11) {
        if (!readSign) {
            state.player->interactionType = InteractionType::SIGN;
            state.player->isInteracting = true;
            state.currText = Text(LEVEL4_LINES[3], "");
        }
        else {
            pathStart = true;
        }   
    }

    // spawn fake monster logic
    if (state.player->getPosition().x > 28) {
        state.enemies[0]->isActive = true;
        state.enemies[1]->isActive = true;
        state.enemies[2]->isActive = true;
    }
    if (state.player->getPosition().x > 40) {
        state.enemies[3]->isActive = true;
    }
    state.enemies[3]->modelMatrix = glm::scale(state.enemies[3]->modelMatrix, glm::vec3(2.5, 2.5, 2.5));

    // make right sign appear once player clear path
    if (state.player->getPosition().x > 62 && !state.objects[1]->isActive) {
        state.objects[1]->isActive = true;
        Mix_PlayChannel(-1, popSfx, 0);
        pathClear = true;
    }

    // stops player from going backwards
    if (pathClear && state.player->getPosition().x < 61.5) {
        state.player->interactionType = InteractionType::SIGN;
        state.player->isInteracting = true;
        state.currText = Text(LEVEL4_LINES[4], "");
        state.player->setPosition(glm::vec3(state.player->getPosition().x + 1, state.player->getPosition().y, state.player->getPosition().z));
    }


}
void Level4::Render(ShaderProgram* program_regular, ShaderProgram* program_lit) {
    Level::Render(program_lit);

    if (state.player->getPosition().x > 52.5) {
        Util::DrawText(program_regular, fontTextureID, "Dead:" + to_string(state.player->isDead), 0.8, -0.2, glm::vec3(56.5, 2.5, 0));
        Util::DisplayText(program_regular, fontTextureID, state.currText, 37.5);
    }
    else if (state.player->getPosition().x > 16) {
        Util::DrawText(program_regular, fontTextureID, "Dead:" + to_string(state.player->isDead), 0.8, -0.2, glm::vec3(state.player->getPosition().x + 4, 2.5, 0));
        Util::DisplayText(program_regular, fontTextureID, state.currText, state.player->getPosition().x - 15);
    }
    else {
        Util::DrawText(program_regular, fontTextureID, "Dead:" + to_string(state.player->isDead), 0.8, -0.2, glm::vec3(20, 2.5, 0));
        Util::DisplayText(program_regular, fontTextureID, state.currText);

    }

}
void Level4::ProcessInput(SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_h: // Interact
            if (!state.player->isInteracting) { 
                Interact();
            }
            break;
        case SDLK_j: // confirm/next
            state.currText.nextLine();
            break;
        case SDLK_k:
            break;
        case SDLK_w:
            if (pathStart && !pathClear) {
                state.player->animIndices = state.player->animUp;
                die();
                break;
            }
        case SDLK_a:
            if (pathStart && !pathClear) {
                state.player->animIndices = state.player->animLeft;
                die();
                break;
            }
        case SDLK_s:
            if (pathStart && !pathClear) {
                state.player->animIndices = state.player->animDown;
                die();
                break;
            }
        }
        break; // SDL_KEYDOWN
    default:
        state.player->ProcessPlayerInput(event);
    }
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
            readSign = true;
        }
        else {
            state.currText = Text(state.objects[1]->lines[0], "");
        }
        break;
    }



}


void Level4::die() {
    state.player->isDead = true;
    state.player->isInteracting = true;
    state.player->interactionType = InteractionType::SIGN;
    state.currText = Text({"!!!", "I was not supposed to look away"}, "");
}