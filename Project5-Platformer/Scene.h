#ifndef SCENE_H
#define SCENE_H

#define GL_SILENCE_DEPRECATION
#ifdef _WINDOWS
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES 1
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Util.h"
#include "Entity.h"
#include "Map.h"
#include "NPC.h"
#include "Player.h"
#include <vector>
#include <string>


struct GameState {
	Mode mode = Mode::DAY;
	Map* map;
	Player* player;
	std::vector<NPC*> enemies;
	std::vector<Entity*> items;
	std::vector<Entity*> allEntities;
	int nextScene;
	bool gameWon = false;
	bool gameLost = false;
};
class Scene {
public:
	GameState state;
	Mix_Music* bgm;
	GLuint fontTextureID;
	float timeMarker;
	int timeToNextSwitch = 4;
	void initSfx();
	virtual void Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(ShaderProgram* program) = 0;
	virtual void ProcessInput(SDL_Event& event);
	virtual void displayText(ShaderProgram* program, GLuint fontTextureID);
	virtual void switchDayAndNight();

	virtual void gameLose();
	virtual void gameWin();
protected:
	glm::mat4 backgroundMatrix;
	GLuint backgroundID;
	Mix_Chunk* clockSfx;
	Mix_Chunk* nextLevelSfx;


};


#endif // !SCENE_H
