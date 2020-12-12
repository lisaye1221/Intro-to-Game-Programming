#include "Level5.h"
#define LEVEL5_WIDTH 33
#define LEVEL5_HEIGHT 18

int talkedToMagenta_5 = 0;

using namespace std;

unsigned int WF = 5; // wood floor
unsigned int LF = 6; // light floor


unsigned int level5_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    75, 29, 29, 29, 29, 74, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 75, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 74,
    22, 40, 41, 42, 43, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, 40, 41, 42, 43, 40, 41, 42, 43, 40, 41, 42, 20,
    22, 48, 49, 50, 51, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 48, 49, 50, 51, 48, 49, 50, 51, 48, 49, 50, 20,
    22, 56, 57, 58, 59, 40, 41, 42, 43, 40, 41, 42, 43, 40, 41, 42, 43, 40, 41, 42, 43, 56, 57, 58, 59, 56, 57, 58, 59, 56, 57, 58, 20,
    22, WF, WF, WF, WF, 48, 49, 50, 51, 48, 49, 50, 51, 48, 49, 50, 51, 48, 49, 50, 51, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, 56, 57, 58, 59, 56, 57, 58, 59, 56, 57, 58, 59, 56, 57, 58, 59, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 67, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 66,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned int level5_clear_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    75, 29, 29, 29, 29, 74, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 75, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 74,
    22, 40, 41, 42, 43, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, 40, 41, 42, 43, 40, 41, 42, 43, 40, 41, 42, 20,
    22, 48, 49, 50, 51, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 48, 49, 50, 51, 48, 49, 50, 51, 48, 49, 50, 20,
    22, 56, 57, 58, 59, 40, 41, 42, 43, 40, 41, 42, 43, 40, 41, 42, 43, 40, 41, 42, 43, 56, 57, 58, 59, 56, 57, 58, 59, 56, 57, 58, 20,
    22, WF, WF, WF, WF, 48, 49, 50, 51, 48, 49, 50, 51, 48, 49, 50, 51, 48, 49, 50, 51, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, 56, 57, 58, 59, 56, 57, 58, 59, 56, 57, 58, 59, 56, 57, 58, 59, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, WF, LF, LF, LF, LF, LF, LF, 01, 01, 01, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, LF, LF, LF, LF, LF, LF, 01, 01, 01, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, 01, 01, 01, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 22, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, LF, 20,
    22, WF, WF, WF, WF, WF, 20, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 67, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 66,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

vector<vector<string>> MAGENTA_LINES_LEVEL5 = {
    { // 0
      "No no, don't come this way",
      "...",
      "No reason, but I think your destination is down the corridor",
      "Talk to that guy over there",
      "...",
      "You want to leave this world don't you?",
      "So stop asking questions and go",
      "This is the last world I think.",
      "You're almost there..."
    },
    {
        "..."
    }
};
vector<vector<string>> LEVEL5_LINES = {
    {// red
        "The yellow slime and the blue slime both won't lie to you."
    },
    {// blue
        "The red slime is a liar"
    },
    {// yellow
        "The blue slime never tells the truth"
    },
    {// green
        "The yellow slime is lying"
    },
    {// purple
        "Both the yellow slime and the green slime are lying to you."
    },
    {
        "No, please! It's not me"
    },
    {
        "(I think I can move on from here)",
        "(Looks like this was the last world)",
        "What would be ahead of this?"
    },
    {
        "(Should I kill this one?)",
        "Kill(J)          Don't kill(K)"
    }
};

vector<vector<string>> HOST_LINES = {
   {
       "Welcome to the liar world",
       "Two out of the six slimes here are telling the truth",
       "Can you kill the honest slimes for me?",
       "Don't kill the liars, of course",
       "Let me know when you are done"
    },
    {
        "Remember, only two of the slimes are telling the truth",
        "Did you kill both of the honest slimes? Yes(J)/No(K)",
    },
    {
        "....?",
        "You did not",
        "Why did you lie?",
        "Goodbye"
    },
    {
        "Thank you!",
        "You may now proceed through the grass patch"
    }
    
};

void Level5::Initialize() {
    Level::Initialize();

    // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    // initialize audio
    bgm = Mix_LoadMUS("assets/audio/Peaceful-Mind.mp3");
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
    GLuint mapTextureID = Util::LoadTexture("assets/inside.png");
    state.map = new Map(LEVEL5_WIDTH, LEVEL5_HEIGHT, level5_data, mapTextureID, 1.0f, 8, 10, INSIDE);
    nextStageAppear = false;

    // Initialize Player
    GLuint textID = Util::LoadTexture("assets/mc2.png");

    state.player = new Player(textID, glm::vec3(2.5, -15, 0));
    state.player->animIndices = state.player->animUp;
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/magenta.png");
    state.magenta = new NPC(textID, glm::vec3(2.5, -5, 0), 0, EntityType::MAGENTA);
    state.allEntities.push_back(state.magenta);
    state.magenta->lines = MAGENTA_LINES_LEVEL5;

    // Initialize NPCs
    textID = Util::LoadTexture("assets/host.png");
    host = new NPC(textID, glm::vec3(19.5, -7, 0), 0, EntityType::NPC);
    host->animIndices = NULL;
    host->animFrames = 1;
    state.enemies.push_back(host);
    state.allEntities.push_back(host);
    host->lines = HOST_LINES;

    // red
    textID = Util::LoadTexture("assets/slime_red.png");
    red = new NPC(textID, glm::vec3(24, -5.5, 0), 0, EntityType::NPC);
    red->lines.push_back(LEVEL5_LINES[0]);
    red->lines.push_back(LEVEL5_LINES[5]);
    state.enemies.push_back(red);
    state.allEntities.push_back(red);

    // blue
    textID = Util::LoadTexture("assets/slime_blue.png");
    blue = new NPC(textID, glm::vec3(28.5, -5.5, 0), 0, EntityType::NPC);
    blue->lines.push_back(LEVEL5_LINES[1]);
    blue->lines.push_back(LEVEL5_LINES[5]);
    state.enemies.push_back(blue);
    state.allEntities.push_back(blue);

    // yellow
    textID = Util::LoadTexture("assets/slime_yellow.png");
    yellow = new NPC(textID, glm::vec3(30, -9.5, 0), 0, EntityType::NPC);
    yellow->lines.push_back(LEVEL5_LINES[2]);
    yellow->lines.push_back(LEVEL5_LINES[5]);
    yellow->setFacing(LEFT);
    state.enemies.push_back(yellow);
    state.allEntities.push_back(yellow);

    // green
    textID = Util::LoadTexture("assets/slime_green.png");
    green = new NPC(textID, glm::vec3(22.5, -14.5, 0), 0, EntityType::NPC);
    green->lines.push_back(LEVEL5_LINES[3]);
    green->lines.push_back(LEVEL5_LINES[5]);
    green->setFacing(UP);
    state.enemies.push_back(green);
    state.allEntities.push_back(green);

    // purple
    textID = Util::LoadTexture("assets/slime_purple.png");
    purple = new NPC(textID, glm::vec3(26.5, -14.5, 0), 0, EntityType::NPC);
    purple->lines.push_back(LEVEL5_LINES[4]);
    purple->lines.push_back(LEVEL5_LINES[5]);
    purple->setFacing(UP);
    state.enemies.push_back(purple);
    state.allEntities.push_back(purple);


}
void Level5::Update(float deltaTime) {

    // Entity updates
    state.player->Update(deltaTime, state.allEntities, state.map);
    state.magenta->Update(deltaTime, state.player, state.allEntities, state.map);
    for (NPC* enemy : state.enemies) {
        enemy->Update(deltaTime, state.player, state.allEntities, state.map);
    }
    for (Entity* object : state.objects) {
        object->Update(deltaTime, state.allEntities, state.map);
    }
    host->modelMatrix = glm::scale(host->modelMatrix, glm::vec3(1.3, 1.5, 1.5));

    // interaction control
    switch (state.player->interactionType) {
    case InteractionType::MAGENTA:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
            state.player->talkedToMangeta();
            talkedToMagenta_5++;
        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
            //nextScene = 6;
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NPC:
        if (state.currText.isEnd) {
            // when player fail to solve
            if (state.player->isDead) {
                // play bad end scene
                state.player->interactionType = InteractionType::NONE;
                
            } 
            else if (riddleSolved && whichNPC == host) {
                state.player->interactionType = InteractionType::NONE;
                // grass patch appear
                if (!nextStageAppear) {
                    state.map->updateMap(level5_clear_data);
                    Mix_PlayChannel(-1, popSfx, 0);
                    nextStageAppear = true;
                }
            }
            else if (killSlime) {
                state.player->interactionType = InteractionType::NONE;
                Mix_PlayChannel(-1, stabSfx, 0);
                whichNPC->isActive = false;
                killSlime = false;
            }
            else if (talkedToHost) {
                state.player->interactionType = InteractionType::CHOICE;
                if (whichNPC == host) {
                    state.currText = Text(HOST_LINES[1], "Host", true);
                }
                else {
                    state.currText = Text(LEVEL5_LINES[7], "", true);
                }
            }
            else {
                state.player->interactionType = InteractionType::NONE;
                if (!talkedToHost && whichNPC == host) { talkedToHost = true; }
                state.player->isInteracting = false;
            }
        }
        break;
    case InteractionType::SIGN:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
            state.player->isInteracting = false;
        }
        break;
    case InteractionType::CHOICE:
        if (state.currText.isEnd) {
            toMakeChoice = true;
        }
        if(buttonChoice != ButtonChoice::NONE){ // made a choice
            state.player->isInteracting = false;
            state.player->interactionType = InteractionType::NONE;
        }
        break;
    case InteractionType::NONE:
        state.player->isInteracting = false;
        break;
    }

    // choice logic
    if (!toMakeChoice) { buttonChoice = ButtonChoice::NONE; }
    else if (buttonChoice == ButtonChoice::CONFIRM) {
        toMakeChoice = false;
        if (whichNPC == host) {
            checkRiddle();
        }
        else { // kill the slime
            state.currText = Text(); // clear text
            killSlime = true;
            state.player->interactionType = InteractionType::NPC;
            state.currText = Text(LEVEL5_LINES[5], "");
        }
    }
    else if (buttonChoice == ButtonChoice::CANCEL) {
        state.player->interactionType = InteractionType::NONE;
        state.currText = Text(); // clear text
        toMakeChoice = false;
    }


}
void Level5::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    Util::DisplayText(program, fontTextureID, state.currText);

    string button = "None";
    if (buttonChoice == ButtonChoice::CONFIRM) { button = "confirm"; }
    else if(buttonChoice == ButtonChoice::CANCEL) { button = "cancel"; }

    Util::DrawText(program, fontTextureID, "Make Choice: " + to_string(toMakeChoice), 0.8, -0.18, glm::vec3(10, 1.5, 0));
    Util::DrawText(program, fontTextureID, "isEnd: " + to_string(state.currText.isEnd), 0.8, -0.18, glm::vec3(10, 0.5, 0));
    Util::DrawText(program, fontTextureID, "Button: " + button, 1.0, -0.2, glm::vec3(20, 2, 0));

}
void Level5::ProcessInput(SDL_Event& event) {
    Level::ProcessInput(event);
}

void Level5::Interact() {

    state.player->isInteracting = true;

    switch (state.player->onWhat) {
    case InteractionType::MAGENTA:
        state.player->interactionType = InteractionType::MAGENTA;
        if (!talkedToMagenta) {
            talkedToMagenta = true;
            state.currText = Text(state.magenta->lines[0], "Magenta");
        }
        else {
            state.currText = Text(state.magenta->lines[1], "Magenta");
        }
        break;
    case InteractionType::NEXTSTAGE:
        state.player->interactionType = InteractionType::NEXTSTAGE;
        state.currText = Text(LEVEL5_LINES[6], "");
        break;
    case InteractionType::NPC:
        state.player->interactionType = InteractionType::NPC;

        // if NPC = host
        if (state.player->didCollideWith(host)) {
            whichNPC = host;
            if (!talkedToHost) {state.currText = Text(HOST_LINES[0], "Host");}
            if (riddleSolved) { state.currText = Text(HOST_LINES[3], "Host"); }
        }
        // if NPC = slimes
        else if (state.player->didCollideWith(red)) {
            whichNPC = red;
            state.currText = Text(red->lines[0], "Red");
        }
        else if (state.player->didCollideWith(blue)) {
            whichNPC = blue;
            state.currText = Text(blue->lines[0], "Blue");
        }
        else if (state.player->didCollideWith(yellow)) {
            whichNPC = yellow;
            state.currText = Text(yellow->lines[0], "Yellow");
        }
        else if (state.player->didCollideWith(green)) {
            whichNPC = green;
            state.currText = Text(green->lines[0], "Green");
        }
        else if (state.player->didCollideWith(purple)) {
            whichNPC = purple;
            state.currText = Text(purple->lines[0], "Purple");
        }
        break;
    }

}

void Level5::checkRiddle() {
    if (!green->isActive && !blue->isActive && yellow->isActive && purple->isActive && red->isActive) {
        riddleSolved = true;
        state.player->interactionType = InteractionType::NPC;
        state.currText = Text(HOST_LINES[3], "Host");
    }
    else { // did not solve
        state.player->interactionType = InteractionType::NPC;
        state.currText = Text(HOST_LINES[2], "Host");
        state.player->isDead = true;
    }
}