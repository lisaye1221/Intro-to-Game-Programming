#ifndef ENDINGDISPLAY_H
#define ENDINGDISPLAY_H

#include "Scene.h"


class EndingDisplay : public Scene {
	glm::mat4 titleMatrix;
	GLuint backgroundID;
	GLuint titleID;

public:
	EndingDisplay(int endingType);
	int endingType;
	Player* getPlayer() override;
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr) override;
	void ProcessInput(SDL_Event& event) override;
};


#endif // !ENDINGDISPLAY_h
