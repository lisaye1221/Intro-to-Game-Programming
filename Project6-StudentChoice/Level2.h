#ifndef LEVEL2_H
#define LEVEL2_H

#include "Level.h"

class Level2 : public Level {
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};


#endif // !LEVEL2_H