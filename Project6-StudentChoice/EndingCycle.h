#ifndef ENDINGCYCLE_H
#define ENDINGCYCLE_H

#include "Level.h"

class EndingCycle : public Level {
	Mix_Chunk* popSfx;
	Mix_Chunk* stabSfx;

	void ending();

public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program_regular, ShaderProgram* program_lit);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};

#endif // ! ENDINGCYCLE_H
