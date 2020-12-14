#include "EndingCycle.h"
#define ENDINGCYCLE_WIDTH 33
#define ENDINGCYCLE_HEIGHT 18

using namespace std;

unsigned int CR = 0; // clear
unsigned int GR = 1;
int linesIndex_endingcycle = 0;
bool startNextLine = true;
float timer = 7;

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

unsigned int endingcycle_data2[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR,
    56, 57, 34, 35, 34, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR,
    48, 49, 35, 34, 35, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR,
    56, 57, 34, 35, 34, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR,
    48, 49, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR,
    56, 57, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR, GR,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48, 49, 48,
    56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56, 57, 56,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned int endingcycle_data3[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 4, 3, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 4, 3, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 45, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 44, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 4, 3, 1,
    1, 43, 42, 40, 40, 43, 42, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 32, 3, 3, 4, 3, 3, 1,
    1, 40, 41, 40, 43, 42, 41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

vector<vector<string>> ENDINGCYCLE_LINES = {

    {
        "Where do you think you're going?"
    },
    {
        "Did you actually think you got rid of me?",
        "HAHAHA",
        "Don't make me laugh",
        "You've fallen right in my trap"
    },
    {
        "Thanks for coming here all by yourself",
        "Saves me a bunch of work",
    },
    {
        "Now goodbye, this time is for real",
        "Hope you will enjoy yourself",
        "Where ever you end up",
        "So long",
        "My friend"
    },

    { //4
        "I finally got out!",
        ".....",
        "It seems like I got my memory back",
        "I don't remember what happened back in there though...",
        "......?",
        "Wait",
        "Where is she?",
        "No please, not this again",
        ".......",
        "I need to go back",
        "To save her"
    }


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
    state.player->animIndices = state.player->animRight;
    state.allEntities.push_back(state.player);
    state.player->setSize(0.8f, 1.0f);

    // Initialize Magenta
    textID = Util::LoadTexture("assets/friend.png");
    state.magenta = new NPC(textID, glm::vec3(16, -8, 0), 0, EntityType::MAGENTA);
    state.magenta->setFacing(RIGHT);
    state.magenta->isActive = false;
    state.allEntities.push_back(state.magenta);

    //// left sign
    textID = Util::LoadTexture("assets/sign.png");
    Entity* sign = new Entity(EntityType::SIGN, textID, glm::vec3(8.5, -6, 0), 0);
    state.objects.push_back(sign);
    state.allEntities.push_back(sign);

    // setting up the lines
    lines.emplace_back(ENDINGCYCLE_LINES[0], "Magenta");
    lines.emplace_back(ENDINGCYCLE_LINES[1], "Magenta");
    lines.emplace_back(ENDINGCYCLE_LINES[2], "Magenta");
    lines.emplace_back(ENDINGCYCLE_LINES[3], "Magenta");


    
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
            magentaWalk = true;
        }
        break;
    case InteractionType::NEXTSTAGE:
        if (state.currText.isEnd) {
            state.player->interactionType = InteractionType::NONE;
            if (state.player->isActive && timer >= 2) {
                startEnding = true;
            }
            else if (shouldDisplayEnding || timer < 2) {
                nextScene = 9;
            }
            else if (state.magenta->getPosition().x <= 3) {
                shouldFadeIn = true; //fadein
                startAnimation3 = true;
                state.map->updateMap(endingcycle_data3);
                state.magenta->setFacing(RIGHT); // face right
                state.magenta->isActive = false;

                state.player->isActive = true;
                state.player->setPosition(glm::vec3(7, -5, 0));
                state.player->animIndices = state.player->animDown; // face down

            }
            else {
                startAnimation2 = true;
                shouldFadeIn = true;// fadein
                state.map = new Map(ENDINGCYCLE_WIDTH, ENDINGCYCLE_HEIGHT, endingcycle_data2, Util::LoadTexture("assets/world.png"), 1.0f, 8, 8, MapType::GRASS);
                state.objects[0]->isActive = false;
                // move magenta
                state.magenta->setPosition(glm::vec3(7, -7, 0));
            }
            
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

    if (startEnding) {
        ending();
    }

    if (startAnimation) {
        if (state.magenta->getPosition().x < 28.5) {
            state.magenta->setSpeed(2.5);
            state.magenta->setFacing(RIGHT);
        }
        else {
            state.currText = Text({ "....", "I've waited too long for this moment", "It's finally time to go back" }, "Magenta");
            state.player->interactionType = InteractionType::NEXTSTAGE;
            state.magenta->setSpeed(0);
            startAnimation = false;
        }
    }

    if (startAnimation2) {
        state.currText = Text(ENDINGCYCLE_LINES[4], "Magenta");
        state.player->interactionType = InteractionType::MAGENTA;
        state.player->isInteracting = true;
        startAnimation2 = false;
    }

    if (magentaWalk) {
        if (state.magenta->getPosition().x > 3) {
            state.magenta->setSpeed(2.5);
            state.magenta->setFacing(LEFT);
        }
        else {
            state.currText = Text({ "This time", "I will bring you back", "Wait for me" }, "Magenta");
            state.player->interactionType = InteractionType::NEXTSTAGE;
            state.magenta->setSpeed(0);
            magentaWalk = false;
        }
    }
    if (startAnimation3) {
        timer -= deltaTime;
        animation3();
    }
}
void EndingCycle::Render(ShaderProgram* program, ShaderProgram* program_lit) {
    Level::Render(program);
    //Level::displayUI(program, fontTextureID);
    Util::DisplayText(program, fontTextureID, state.currText);
    //Util::DrawText(program, fontTextureID, "startAnimation: " + to_string(startAnimation), 1.0, -0.2, glm::vec3(16, 1, 0));

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
        state.currText = Text({"So this is the end?"}, "");
        break;
    case InteractionType::SIGN:
        state.player->interactionType = InteractionType::SIGN;
        state.currText = Text({ "The Path to the Outer World" }, "");
    }



}

void EndingCycle::ending() {
    if (linesIndex_endingcycle >= lines.size()) { return; }
    if (startNextLine) {
        state.currText = lines[linesIndex_endingcycle];
        state.player->interactionType = InteractionType::SIGN;
        state.player->isInteracting = true;
        startNextLine = false;
    }
    if (linesIndex_endingcycle == 0 && state.currText.isAtEnd()) {
        // magenta reappear
        state.magenta->isActive = true;
        if (!changeMusic) {
            Mix_HaltMusic();
            bgm = Mix_LoadMUS("assets/audio/92nd-Floor.mp3");
            Mix_PlayMusic(bgm, -1);
            changeMusic = true;
        }
    }
    if (linesIndex_endingcycle == lines.size() - 1 && state.currText.isAtEnd()) {
        // checks if we're done
        state.player->isActive = false;
        startAnimation = true;
        startEnding = false;
        Mix_PlayChannel(-1, stabSfx, 0);
        linesIndex_endingcycle++;
    }
    if (linesIndex_endingcycle < lines.size() - 1 && state.currText.isAtEnd()) {
        startNextLine = true;
        linesIndex_endingcycle++;
    }
}

void EndingCycle::animation3() {

    if (timer < 4) {
        if (!changeToMangeta) {
            state.player->setTextureID(Util::LoadTexture("assets/magenta.png"));
            changeToMangeta = true;
        }
    }
    if (timer < 2) {
        if(!state.magenta->isActive){
            state.magenta->isActive = true;
            state.currText = Text({"Where am I?", "Why am I here?", "I should find the way home..."}, "");
            state.player->interactionType = InteractionType::NEXTSTAGE;
            state.player->isInteracting = true;
            shouldDisplayEnding = true;
        }
    }

}
