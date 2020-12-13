#ifndef LEVEL3_H
#define LEVEL3_H

#include "Level.h"

class Level3 : public Level {
	Mix_Chunk* popSfx;
	Mix_Chunk* stabSfx;
	bool attackStart = false;
	bool attackEnd = false;
	float countdownTime = 30;
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};


#endif // !LEVEL3_H