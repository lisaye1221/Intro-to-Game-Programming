#include "Effects.h"
Effects::Effects(glm::mat4 projectionMatrix, glm::mat4 viewMatrix)
{
	// Non textured Shader
	program.Load("shaders/vertex.glsl", "shaders/fragment.glsl");
	program.SetProjectionMatrix(projectionMatrix);
	program.SetViewMatrix(viewMatrix);
	currentEffect = NONE;
	alpha = 0;
	speed = 1.0f;

	viewOffset = glm::vec3(0, 0, 0);
}
void Effects::DrawOverlay()
{
	glUseProgram(program.programID);
	float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
	glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, vertices);
	glEnableVertexAttribArray(program.positionAttribute);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(program.positionAttribute);
}

void Effects::Start(EffectType effectType, float effectSpeed)
{
	currentEffect = effectType;
	speed = effectSpeed;
	switch (currentEffect) {
	case NONE:
		break;
	case FADEIN:
		// start as full alpha, cover everything at the beginning
		alpha = 1.0f;
		break;
	case FADEOUT:
		alpha = 0.0f;
		break;
	case GROW:
		size = 0.0f;
		break;
	case SHRINK:
		size = 10.0f;
		break;
	case SHAKE:
		timeLeft = 1.0f; // 1 second
		break;
	}
}
void Effects::Update(float deltaTime)
{
	switch (currentEffect) {
	case NONE:
		break;
	case FADEIN:
		// decrease the alpha over time so it looks like it's 
		// fading away
		alpha -= deltaTime * speed;
		if (alpha <= 0) {
			// once alpha is down to zero, we're done with this effect
			currentEffect = NONE;
		}
		break;
	case FADEOUT:
		// decrease the alpha over time so it looks like it's 
		// fading away
		alpha += deltaTime * speed;
		// you might want to keep the black square so we want to keep drawing
		//if (alpha >= 1) {
		//	// once alpha is down to zero, we're done with this effect
		//	currentEffect = NONE;
		//}
		break;
	case GROW:
		size += deltaTime * speed;
		break;
	case SHRINK:
		size -= deltaTime * speed;
		if (size <= 0) {
			// once alpha is down to zero, we're done with this effect
			currentEffect = NONE;
		}
		break;
	case SHAKE:
		timeLeft -= deltaTime * speed;
		if (timeLeft <= 0) {
			// reset the view back to normal
			viewOffset = glm::vec3(0, 0, 0);
			currentEffect = NONE;
		}
		else {
			// max & min dictates how big the shake is 
			float max = 0.1f;
			float min = -0.1f;
			float r = ((float)rand() / RAND_MAX) * (max - min) + min;
			viewOffset = glm::vec3(r, r, 0);
		}
		break;
	}
}
void Effects::Render()
{
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(16, -9, 0));
	switch (currentEffect) {
	case NONE:
		return;
		break;
	case FADEOUT: // does the same thing as FADEIN here
	case FADEIN:
		// scale up so it covers the whole window
		modelMatrix = glm::scale(modelMatrix, glm::vec3(32, 32, 1));
		program.SetModelMatrix(modelMatrix);
		// set the layer color to black
		program.SetColor(0, 0, 0, alpha);
		DrawOverlay();
		break;
	case GROW:
	case SHRINK:
		// scale up so it covers the whole window
		modelMatrix = glm::scale(modelMatrix, glm::vec3(size, size * 0.75f, 1));
		program.SetModelMatrix(modelMatrix);
		program.SetColor(0, 0, 0, 1);
		DrawOverlay();
		break;
	case SHAKE: // we actually don't draw anything
		break;
	}
}