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
#include "Effects.h"
#include "Entity.h"
#include "Map.h"
#include "NPC.h"
#include "Player.h"
#include <vector>
#include <string>



class Scene {
public:
	Mix_Music* bgm;
	GLuint fontTextureID;
	EffectType effect = EffectType::NONE;
	float effectSpd = 1.0f;
	int nextScene = -1;
	bool viewScrolls = false;
	void initSfx();
	
	virtual Player* getPlayer() = 0;
	virtual int getWorldNum() const;
	virtual void Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr) = 0;
	virtual void ProcessInput(SDL_Event& event) = 0;

	bool shouldFadeIn = false;
	bool shouldFadeOut = false;
protected:
	glm::mat4 backgroundMatrix;
	GLuint backgroundID;
	int worldNum;
	void playEffect(EffectType type, float spd);
};


#endif // !SCENE_H
