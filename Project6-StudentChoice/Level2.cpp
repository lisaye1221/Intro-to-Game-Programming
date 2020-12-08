#include "Level2.h"
#define LEVEL2_WIDTH 33
#define LEVEL2_HEIGHT 18

int talkedToMagenta_2 = 0;

using namespace std;

unsigned int level2_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    01, 01, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 32, 01, 32, 11, 11, 11, 11, 11, 11, 01, 34, 35, 01,
    01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 01, 01, 01, 11, 01, 01, 01, 01, 11, 01, 35, 34, 01,
    01, 01, 11, 11, 11, 11, 01, 01, 11, 11, 01, 01, 11, 11, 11, 01, 01, 11, 11, 11, 01, 01, 01, 11, 01, 01, 11, 11, 11, 01, 01, 01, 01,
    01, 01, 11, 01, 01, 11, 11, 11, 11, 01, 01, 01, 11, 01, 01, 01, 01, 11, 01, 11, 11, 01, 01, 11, 01, 01, 01, 11, 11, 01, 01, 01, 01,
    01, 01, 11, 01, 01, 01, 01, 01, 23, 11, 11, 11, 11, 01, 01, 11, 11, 11, 01, 11, 29, 01, 01, 11, 01, 01, 01, 11, 01, 01, 01, 01, 01,
    01, 01, 11, 11, 11, 11, 11, 01, 01, 01, 11, 01, 01, 01, 11, 11, 01, 01, 01, 11, 01, 01, 01, 11, 01, 01, 11, 11, 01, 01, 11, 11, 11,
    01, 01, 11, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 11, 11, 01, 01, 11, 11, 01, 01, 11, 11, 01, 01, 11, 01, 01,
    01, 01, 11, 01, 01, 01, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 01, 01, 01, 11, 11, 11, 01, 01, 11, 01, 01, 01, 11, 01, 01,
    01, 01, 01, 01, 01, 01, 11, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 01, 01, 11, 39, 01, 01,
    01, 01, 11, 11, 45, 01, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 01, 01, 11, 11, 11, 11, 11, 11, 11, 11, 11, 01, 01, 11, 01, 01, 01,
    01, 01, 11, 11, 44, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 01, 01, 01,
    01, 01, 11, 11, 11, 01, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 01, 01, 11, 01, 01, 11, 11, 11, 11, 11, 11, 11, 01, 01,
    01, 01, 11, 11, 11, 11, 11, 01, 01, 01, 01, 01, 01, 11, 22, 11, 11, 11, 31, 01, 01, 11, 01, 01, 01, 11, 01, 01, 01, 01, 01, 01, 01,
    01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 01, 11, 11, 11, 01, 01, 11, 11, 01, 01, 01,
    01, 01, 11, 11, 11, 11, 11, 11, 01, 01, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 01, 01, 01, 01, 01, 11, 11, 11, 11, 11,
    01, 01, 11, 11, 11, 11, 11, 11, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 11, 11, 11, 11, 11,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
vector<vector<string>> MAGENTA_LINES_LEVEL2 = {
    {
      "Hi again, you found me!",
      "What am I doing here?",
      "I felt I should help you find your way home!",
      "It's kind of exciting, don't you think?",
      "Let's see...",
      "Seems like this is just a regular maze.",
      "You see the patch of blue flower?",
      "That's your goal again!"
    },
    {
       "Hmm? Did you get lost?",
       "A tip? For a maze?",
       "They say if you put your hand on the wall and keep walking",
       "you'll eventually reach the end!",
       "Isn't that cool? You should try that out!"
    },
    {
        "It's pretty rare to have visitors here",
        "Me? I'm a slime.",
        "A gooo one of course",
        "Was that a gooo one? :)",
        "Ok ok, no more slime puns",
        "You sure are chatty...",
        "You should probably get going",
        "Don't you want to get home quicker?"
    }
};
vector<vector<string>> LEVEL2_LINES = {
    {"(It is just a patch of grass)"},
    {"(These are just some flowers)"},
    {"(I think I can move on from here)"}
};


void Level2::Initialize() {
    Level::Initialize();

    // initialize audio
    bgm = Mix_LoadMUS("assets/audio/Lost-Jungle.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME / 5);
    // Check load
    if (bgm == NULL) {
        std::cout << "Fail to load music. " << Mix_GetError() << std::endl;
        assert(false);
    }
    // loop the bgm
    Mix_PlayMusic(bgm, -1);

    // initialize map
    GLuint mapTextureID = Util::LoadTexture("assets/world1.png");
    state.map = new Map(LEVEL2_WIDTH, LEVEL2_HEIGHT, level2_data, mapTextureID, 1.0f, 8, 16, WORLD);


    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(1, -2, 0));
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/magenta.png");
    state.magenta = new NPC(textID, glm::vec3(21, -1.5, 0), 0, EntityType::MAGENTA);
    state.allEntities.push_back(state.magenta);
    state.magenta->lines = MAGENTA_LINES_LEVEL2;



}
void Level2::Update(float deltaTime) {

    state.player->Update(deltaTime, state.allEntities, state.map);
    state.magenta->Update(deltaTime, state.player, state.allEntities, state.map);

    switch (state.player->interactionType) {
    case InteractionType::MAGENTA:
        if (state.currText.isEnd) { 
            state.player->interactionType = InteractionType::NONE; 
            state.player->talkedToMangeta();
            talkedToMagenta_2++;
        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
            nextScene = 3;
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NONE:
        state.player->isInteracting = false;
        break;
    }


}
void Level2::Render(ShaderProgram* program) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);
    //Util::DrawText(program, fontTextureID, to_string(talkedToMagenta_2), 0.8, -0.2, glm::vec3(20, 2, 0));
}
void Level2::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);
}

void Level2::Interact() {

    state.player->isInteracting = true;

    switch (state.player->onWhat) {
    case InteractionType::MAGENTA:
        state.player->interactionType = InteractionType::MAGENTA;
        if (talkedToMagenta_2 == 0) {
            state.currText = Text(state.magenta->lines[0], "Magenta");
        }
        else {
            if (talkedToMagenta_2 >= MAGENTA_LINES_LEVEL2.size()) { talkedToMagenta_2 = 1; }
            state.currText = Text(state.magenta->lines[talkedToMagenta_2], "Magenta");
        }
        break;
    case InteractionType::NEXTSTAGE:
        state.player->interactionType = InteractionType::NEXTSTAGE;
        state.currText = Text(LEVEL2_LINES[2], "");
        break;
    
    }



}