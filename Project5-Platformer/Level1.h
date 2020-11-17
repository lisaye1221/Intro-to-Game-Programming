#ifndef LEVEL1_H
#define LEVEL1_H

#include "Scene.h"
class Level1 : public Scene {
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
};


#endif // !LEVEL1_H

