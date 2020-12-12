#ifndef BADENDDEATH_H
#define BADENDDEATH_H

#include "Scene.h"


class BadEndDeath : public Scene {
	glm::mat4 titleMatrix;
	GLuint backgroundID;
	GLuint titleID;

public:
	Player* getPlayer() override;
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr) override;
	void ProcessInput(SDL_Event& event) override;
};


#endif // !BADENDDEATH_h
