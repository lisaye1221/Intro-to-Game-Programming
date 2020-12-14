#ifndef ENDINGSACRIFICE_H
#define ENDINGSACRIFICE_H

#include "Level.h"

class EndingSacrifice : public Level {
	bool startEnding = false;
	std::vector<Text> lines;

	bool shouldDisplayEnding = false;
	bool startNextLine = true;

	bool playerWalkForward = false;
	bool playerWalkBack = false;

public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program_regular, ShaderProgram* program_lit);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};

#endif // ! ENDINGSACRIFICE_H
