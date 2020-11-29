#ifndef LEVEL_H
#define LEVEL_H

#include "Scene.h"

struct GameState {
	Map* map;
	Player* player;
	std::vector<NPC*> enemies;
	std::vector<Entity*> items;
	std::vector<Entity*> allEntities;
};

class Level: public Scene {
public:
	GameState state;
	Player* getPlayer() override;
	virtual void Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(ShaderProgram* program) = 0;
	virtual void ProcessInput(SDL_Event& event);

	// looks at what object player is on to determine how interaction will proceed
	virtual void Interact() = 0;

	//virtual void gameLose();
	//virtual void gameWin();
protected:
	glm::mat4 backgroundMatrix;
	GLuint backgroundID;


};


#endif // !LEVEL_H
