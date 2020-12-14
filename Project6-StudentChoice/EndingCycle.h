#ifndef ENDINGCYCLE_H
#define ENDINGCYCLE_H

#include "Level.h"

class EndingCycle : public Level {
	Mix_Chunk* popSfx;
	Mix_Chunk* stabSfx;
	bool startEnding = false;
	void ending();
	void animation3();
	std::vector<Text> lines;
	std::vector<Text> linesScene2;

	bool startAnimation = false;
	bool changeMusic = false;

	bool startAnimation2 = false;
	bool magentaWalk = false;
	bool startAnimation3 = false;
	bool changeToMangeta = false;
	bool shouldDisplayEnding = false;

	

public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program_regular, ShaderProgram* program_lit);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};

#endif // ! ENDINGCYCLE_H
