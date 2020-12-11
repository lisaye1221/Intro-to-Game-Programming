#ifndef LEVEL1_H
#define LEVEL1_H

#include "Level.h"

class Level1 : public Level {
	Mix_Chunk* popSfx;
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr);
	virtual void ProcessInput(SDL_Event& event);
	virtual void Interact();
};


#endif // !LEVEL1_H

