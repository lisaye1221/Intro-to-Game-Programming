#ifndef LEVEL4_H
#define LEVEL4_H

#include "Level.h"

class Level4 : public Level {
	Mix_Chunk* popSfx;
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};


#endif // !LEVEL4_H