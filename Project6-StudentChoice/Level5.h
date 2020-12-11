#ifndef LEVEL5_H
#define LEVEL5_H

#include "Level.h"

class Level5 : public Level {
	Mix_Chunk* popSfx;
	Mix_Chunk* stabSfx;
	NPC* host;
	NPC* red;
	NPC* blue;
	NPC* yellow;
	NPC* green;
	NPC* purple;

	bool talkedToMagenta = false;
	bool talkedToHost = false;
	NPC* whichNPC = nullptr;
	bool riddleSolved = false;
	bool killSlime = false;

	void checkRiddle();
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};


#endif // !LEVEL5_H