#ifndef MAINMENU_H
#define MAINMENU_H

#include "Scene.h"


class MainMenu : public Scene {
	glm::mat4 backgroundMatrix;
	glm::mat4 titleMatrix;
	GLuint backgroundID;
	GLuint titleID;
	
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
};


#endif // !MAINMENU_H
