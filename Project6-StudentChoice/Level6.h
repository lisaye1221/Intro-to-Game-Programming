#ifndef LEVEL6_H
#define LEVEL6_H

#include "Level.h"

enum class Ending {NONE, BETRAYAL, CYCLE, SACRIFICE, WELCOME_HOME, BAD_END};

class Level6 : public Level {
	Mix_Chunk* popSfx;
	Mix_Chunk* stabSfx;
	Ending ending = Ending::NONE;
	void die();

	void endingSacrifice();
	void endingWelcomeHome();
	void preBattle();
	void battleLost();

	bool endingSacrificeScene = false;
	bool endingWelcomeHomeScene = false;
	bool preBattleScene = false;
	bool battleLostScene = false;

	std::vector<Text> endingSacrificeLines;
	std::vector<Text> welcomeHomeLines;
	std::vector<Text> preBattleLines;

	bool canAdvance = false;
	bool magentaWalk = false;
	bool battleStart = false;
	bool battleWin = false;

	float battleDuration = 10;

public:
	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Render(ShaderProgram* program_regular, ShaderProgram* program_lit);
	virtual void ProcessInput(SDL_Event& event);

	virtual void Interact();
};

#endif // ! LEVEL6_H
