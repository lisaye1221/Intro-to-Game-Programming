#ifndef LEVEL3_H
#define LEVEL3_H

#include "Scene.h"
class Level3 : public Scene {
public:
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render(ShaderProgram* program) override;
};


#endif // LEVEL3_H

