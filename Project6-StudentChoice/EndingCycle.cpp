#include "EndingCycle.h"
#define ENDINGCYCLE_WIDTH 33
#define ENDINGCYCLE_HEIGHT 18

using namespace std;

unsigned int CR = 0; // clear

unsigned int endingcycle_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 66, 67, 66, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 67, 66, 67, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 66, 67, 66, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR, CR,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


void EndingCycle::Initialize() {
    Level::Initialize();
    worldNum = 6;
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
    stabSfx = Mix_LoadWAV("assets/audio/stab.wav");
    Mix_VolumeChunk(popSfx, MIX_MAX_VOLUME / 4);
    Mix_VolumeChunk(stabSfx, MIX_MAX_VOLUME / 4);

    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/world1.png");
    state.map = new Map(ENDINGCYCLE_WIDTH, ENDINGCYCLE_HEIGHT, endingcycle_data, mapTextureID, 1.0f, 8, 16, MapType::WORLD);

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(1, -7.5, 0));
    state.player->animIndices = state.player->animUp;
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/friend.png");
    state.magenta = new NPC(textID, glm::vec3(16, -6.5, 0), 0, EntityType::MAGENTA);
    state.magenta->isActive = false;
    state.allEntities.push_back(state.magenta);

    //// left sign
    textID = Util::LoadTexture("assets/sign.png");
    Entity* sign = new Entity(EntityType::SIGN, textID, glm::vec3(8.5, -6, 0), 0);
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    // setting up the lines

    
}
void EndingCycle::Update(float deltaTime) {

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

        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
           
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
void EndingCycle::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);
}
void EndingCycle::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);

}

void EndingCycle::Interact() {

    state.player->isInteracting = true;

    switch (state.player->onWhat) {
    case InteractionType::MAGENTA:
        state.player->interactionType = InteractionType::MAGENTA;
        
        break;
    case InteractionType::NEXTSTAGE:
        state.player->interactionType = InteractionType::NEXTSTAGE;
        ending();
        break;
    case InteractionType::SIGN:
        state.player->interactionType = InteractionType::SIGN;
        state.currText = Text({ "The Path to the Outer World" }, "");
    }



}

void EndingCycle::ending() {

}
