#ifndef ENDINGBETRAYAL_H
#define ENDINGBETRAYAL_H

#include "Scene.h"


class EndingBetrayal : public Scene {
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


#endif // !ENDINGBETRAYAL_H
