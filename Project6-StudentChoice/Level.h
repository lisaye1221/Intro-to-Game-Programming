#ifndef LEVEL_H
#define LEVEL_H

#include "Scene.h"

enum class ButtonChoice {NONE, CONFIRM, CANCEL };

struct GameState {
	Map* map;
	Player* player;
	NPC* magenta;
	std::vector<NPC*> enemies;
	std::vector<Entity*> objects;
	std::vector<Entity*> allEntities;
	Text currText;
};

class Level: public Scene {
public:
	GameState state;
	Player* getPlayer() override;
	int getWorldNum() const;
	virtual void Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr) = 0;
	virtual void ProcessInput(SDL_Event& event);

	// looks at what object player is on to determine how interaction will proceed
	virtual void Interact() = 0;

	virtual void displayUI(ShaderProgram* program, GLuint fontTextureID) const;

	//virtual void gameLose();
	//virtual void gameWin();
protected:
	glm::mat4 backgroundMatrix;
	GLuint backgroundID;
	bool nextStageAppear = true;
	ButtonChoice buttonChoice = ButtonChoice::NONE;
	bool toMakeChoice = false;

};


#endif // !LEVEL_H
