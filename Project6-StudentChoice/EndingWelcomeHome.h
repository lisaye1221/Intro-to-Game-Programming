#ifndef ENDINGWELCOMEHOME_H
#define ENDINGWELCOMEHOME_H

#include "Level.h"

class EndingWelcomeHome : public Level {
	Mix_Chunk* popSfx;
	bool startEnding = false;
	std::vector<Text> lines;

	bool shouldDisplayEnding = false;
	bool startNextLine = true;

	bool walkForward = false;
	bool walkHome = false;

public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program_regular, ShaderProgram* program_lit);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};

#endif // ! ENDINGWELCOMEHOME_H
