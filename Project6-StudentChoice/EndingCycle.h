#ifndef ENDINGCYCLE_H
#define ENDINGCYCLE_H

#include "Level.h"


class EndingCycle : public Level {
	glm::mat4 titleMatrix;
	GLuint backgroundID;
	GLuint titleID;
	bool showEnding = false;
public:
	Map* map;
	NPC* magenta;
	Player* getPlayer() override;
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program, ShaderProgram* program_lit = nullptr) override;
	void ProcessInput(SDL_Event& event) override;
};


#endif // !ENDINGCYCLE_H
