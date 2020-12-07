#ifndef LEVEL3_H
#define LEVEL3_H

#include "Level.h"

class Level3 : public Level {
	bool attackStart = false;
	bool attackEnd = false;
	float countdownTime = 5;
public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};


#endif // !LEVEL3_H