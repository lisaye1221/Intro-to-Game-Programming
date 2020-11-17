#ifndef LEVEL2_H
#define LEVEL2_H

#include "Scene.h"
class Level2 : public Scene {
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
};


#endif // LEVEL2_H

