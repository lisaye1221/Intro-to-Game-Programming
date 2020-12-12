#include "Level6.h"
#define LEVEL6_WIDTH 33
#define LEVEL6_HEIGHT 18

bool talkedToMagenta_6 = false;

using namespace std;

int GS = 01; // grass

int linesIndex = 0;
bool shouldStart = true;
bool canChangeMusic = true;

unsigned int level6_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, GS, 34, 35, 34, GS, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, GS, 35, 34, 35, GS, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 34, 35, 34, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49,
    56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57,
    48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49,
    56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57,
    48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49,
    56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, GS, GS, GS, GS, GS, GS, GS, GS, GS, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, GS, GS, GS, GS, GS, GS, GS, GS, GS, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

vector<vector<string>> MAGENTA_LINES_LEVEL6 = {
    {
        "Hey, where are you going?",
        "You're not going to talk to me?"
    },
    { // 1
      "...",
      "What makes you say that?",
      "We're friends, right?"
    },
    { // 2
        "...",
        "So you chose to believe a random person",
        "and doubt your friend who has been with you all this time?",
        "......",
        "Well I guess there is no point in hiding anymore"
    },
    { // 3
       "This is the real me",
       "...",
       "I've been trapped in 'this world' for who knows how long",
       "Nobody has reached this far",
       "You want to go home?",
       "I want to go home too...",
       "Do you see that flower patch behind me?",
       "That is the portal to the real world",
       "And to get out, I need to sacrifice somebody",
       "If you haven't noticed by now",
       "I came along with you to lure you here",
       "....."
    },
    { // 4
        "If I kill you right here", 
        "I will be able to go home",
        "Sorry, you're not a bad person",
        "But I need you to do a favor for me",
        "Can you please",
        "Die for me?"
    },
    { // 5
        "If I kill you right here",
        "I will be able to go home",
        "But I can't doing something like that...",
        "After all, you're my friend",
        "Right?",
        "...",
        "So I'll let you go",
    },
    { //6
        "Go on! You don't have to pity me",
        "This is what you wanted right?",
        "...",
        "I'll just find another target",
    },
    { // 7
        "Wait!",
        "...",
        "Thanks for talking to me so much",
        "It's been a bit lonely here by myself...",
        "Goodbye, my friend"
    },
    { //8
        "...",
        "Wait",
        "Is that an orb?",
        "Is it THAT orb?",
        "Can I see it?",
        "...",
        "YES, where did you find this?",
        "I've been looking for this all this time and I never found it!",
        "This orb will allow us both to get out of here",
        "Come on, let's go!",
    },
    { //9
        "...",
        "Thank you",
        "Maybe we will meet again in the real world"
    },
};
vector<vector<string>> LEVEL6_LINES = {
    {
        "Press Space Bar to fight back"
    },
    { // 1
        "Magenta, are you hiding something from me?",
    },
    { // 2 
        "In the last world, there were 6 slimes",
        "You were the 6th one that was lying right?",
    },
    {
        "(Was that it?)",
        "(Am I finally done?)",
        "(I think I can move on from here)"
    }
};


void Level6::Initialize() {
    Level::Initialize();
    worldNum = 6;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // initialize audio
    bgm = Mix_LoadMUS("assets/audio/wind.wav");
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
    GLuint mapTextureID = Util::LoadTexture("assets/world.png");
    state.map = new Map(LEVEL6_WIDTH, LEVEL6_HEIGHT, level6_data, mapTextureID, 1.0f, 8, 8, WORLD);
    nextStageAppear = false;

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(16, -15.5, 0));
    state.player->animIndices = state.player->animUp;
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/magenta.png");
    state.magenta = new NPC(textID, glm::vec3(16, -5.5, 0), 0, EntityType::MAGENTA);
    state.allEntities.push_back(state.magenta);
    state.magenta->lines = MAGENTA_LINES_LEVEL6;

    //// left sign
    //textID = Util::LoadTexture("assets/sign_desert.png");
    //Entity* sign = new Entity(EntityType::SIGN, textID, glm::vec3(8.5, -4, 0), 0);
    //sign->lines.push_back(LEVEL3_LINES[0]);
    //sign->lines.push_back(LEVEL3_LINES[1]);
    //state.objects.push_back(sign);
    //state.allEntities.push_back(sign);

    //// right sign
    //sign = new Entity(EntityType::SIGN, textID, glm::vec3(27, -5, 0), 0);
    //sign->lines.push_back(LEVEL3_LINES[2]); // this line will show at first
    //sign->lines.push_back(LEVEL3_LINES[3]); // this line will show after surviving the attack
    //sign->isActive = false;
    //state.objects.push_back(sign);
    //state.allEntities.push_back(sign);

    // setting up the lines
    endingSacrificeLines.emplace_back(LEVEL6_LINES[1], "");
    endingSacrificeLines.emplace_back(state.magenta->lines[1], "Magenta");
    endingSacrificeLines.emplace_back(LEVEL6_LINES[2], "");
    endingSacrificeLines.emplace_back(state.magenta->lines[2], "Magenta", "");
    // Magenta reveals
    endingSacrificeLines.emplace_back(state.magenta->lines[3], "Magenta", "");
    endingSacrificeLines.emplace_back(state.magenta->lines[5], "Magenta", "");
}
void Level6::Update(float deltaTime) {

    // Entity updates
    state.player->Update(deltaTime, state.allEntities, state.map);
    state.magenta->Update(deltaTime, state.player, state.allEntities, state.map);
    for (NPC* enemy : state.enemies) {
        enemy->Update(deltaTime, state.player, state.allEntities, state.map);
    }
    for (Entity* object : state.objects) {
        object->Update(deltaTime, state.allEntities, state.map);
    }

    // check if good end
    if (state.player->getMagentaTalks() >= 10 && ending == Ending::NONE) {
        state.player->hasOrb ? ending = Ending::WELCOME_HOME : ending = Ending::SACRIFICE;
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
            nextScene = 1;
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

    // forces player to interact with Magenta
    if (state.player->getPosition().y > -5 && !talkedToMagenta_6) {
        state.currText = Text(state.magenta->lines[0], "Magenta");
        state.player->isInteracting = true;
        state.player->interactionType = InteractionType::MAGENTA;
        state.player->setPosition(glm::vec3(state.player->getPosition().x , state.player->getPosition().y - 2, state.player->getPosition().z));
    }

    if (endingSacrificeScene) {
        endingSacrifice();
        if (canAdvance && canChangeMusic) {
            Mix_HaltMusic();
            bgm = Mix_LoadMUS("assets/audio/Distant-Mountains.mp3");
            Mix_PlayMusic(bgm, -1);
            canChangeMusic = false;
        }
    }
    else if (endingWelcomeHomeScene) {
        endingWelcomeHome();
    }
    else if (preBattleScene) {
        preBattle();
    }
    else if (battleLostScene) {
        battleLost();
    }

}
void Level6::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);
    Util::DrawText(program, fontTextureID, "isAtEnd:" + to_string(state.currText.isAtEnd()), 0.8, -0.2, glm::vec3(20, 2.5, 0));
}
void Level6::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);
}

void Level6::Interact() {

    state.player->isInteracting = true;

    switch (state.player->onWhat) {
    case InteractionType::MAGENTA:
        state.player->interactionType = InteractionType::MAGENTA;
        talkedToMagenta_6 = true;
        if (ending == Ending::SACRIFICE) {
            if(canAdvance){
                state.currText = Text(state.magenta->lines[6], "Magenta");
            }
            else {
                endingSacrificeScene = true;
            }
        }
        else if (ending == Ending::WELCOME_HOME) {
            endingWelcomeHomeScene = true;
        }
        else {
            preBattleScene = true;
        }
        break;
    case InteractionType::NEXTSTAGE:
        state.player->interactionType = InteractionType::NEXTSTAGE;
        if (ending == Ending::SACRIFICE) {
            state.currText = Text(state.magenta->lines[7], "Magenta");
            state.magenta->setFacing(UP);
        }
        else{
            state.currText = Text(LEVEL6_LINES[0], "");
        }
        
        break;
    case InteractionType::SIGN:
        state.player->interactionType = InteractionType::SIGN;
        break;
    }



}

void Level6::endingSacrifice() {

    if (shouldStart) {
        state.currText = endingSacrificeLines[linesIndex];
        state.player->interactionType = InteractionType::SIGN;
        state.player->isInteracting = true;
        shouldStart = false;
    }
    if (linesIndex == 3 && state.currText.isAtEnd()) {
        // magenta reveal
        state.magenta->setTextureID(Util::LoadTexture("assets/friend.png"));
    }
    if (linesIndex == endingSacrificeLines.size() - 1 && state.currText.isAtEnd()) {
        // checks if we're done
        endingSacrificeScene = false;
        canAdvance = true;
    }
    if (linesIndex < endingSacrificeLines.size() - 1 && state.currText.isAtEnd()) {
        shouldStart = true;
        linesIndex++;
    }
    
    
}
void Level6::endingWelcomeHome() {

}
void Level6::preBattle() {

}
void Level6::battleLost() {

}