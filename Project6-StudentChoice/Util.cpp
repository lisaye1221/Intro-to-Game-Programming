#include "Util.h"
#define STB_IMAGE_IMPLEMENTATION
#include <SDL_image.h>
#include "stb_image.h"
using namespace std;

GLuint Util::LoadTexture(const char* filePath) {
	int w, h, n;
	unsigned char* image = stbi_load(filePath, &w, &h, &n, STBI_rgb_alpha);
	if (image == NULL) {
		std::cout << "Unable to load image. Make sure the path is correct\n";
		assert(false);
	}
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	stbi_image_free(image);
	return textureID;
}

void Util::DrawText(ShaderProgram* program, GLuint fontTexture, std::string text, float size,
	float spacing, glm::vec3 position) {
	float width = 1.0f / 16.0f;
	float height = 1.0 / 16.0f;
	std::vector<float> vertices;
	std::vector<float> texCoords;
	for (int i = 0; i < text.size(); i++) {
		int index = (int)text[i];
		float u = (float)(index % 16) / 16.0f;
		float v = (float)(index / 16) / 16.0f;
		float offset = (size + spacing) * i;
		texCoords.insert(texCoords.end(), {
		u, v,
		u, v + height,
		u + width, v,
		u + width, v + height,
		u + width, v,
		u, v + height,
	});
	vertices.insert(vertices.end(), {
	offset + (-0.5f * size), 0.5f * size,
	offset + (-0.5f * size), -0.5f * size,
	offset + (0.5f * size), 0.5f * size,
	offset + (0.5f * size), -0.5f * size,
	offset + (0.5f * size), 0.5f * size,
	offset + (-0.5f * size), -0.5f * size,
			});
	}
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, position);
	program->SetModelMatrix(modelMatrix);
	glUseProgram(program->programID);
	glVertexAttribPointer(program->positionAttribute, 2, GL_FLOAT, false, 0, vertices.data());
	glEnableVertexAttribArray(program->positionAttribute);
	glVertexAttribPointer(program->texCoordAttribute, 2, GL_FLOAT, false, 0, texCoords.data());
	glEnableVertexAttribArray(program->texCoordAttribute);
	glBindTexture(GL_TEXTURE_2D, fontTexture);
	glDrawArrays(GL_TRIANGLES, 0, (int)(text.size() * 6));
	glDisableVertexAttribArray(program->positionAttribute);
	glDisableVertexAttribArray(program->texCoordAttribute);
}

void Util::DisplayText(ShaderProgram* program, GLuint fontTextureID, const Text& text) {

	
	if (text.isEnd && !text.getIsQuestion()) { return; }

	// display speaker
	if (text.getSpeaker() != "") {
		DrawText(program, fontTextureID, text.getSpeaker() + ": ", 0.8, -0.1, glm::vec3(1, -19, 0));
	}
	int x = text.getSpeaker() != "" ? 7 : 5;
	// display line
	string currLine = text.getCurLine();

	if(currLine.size() < 35){
		DrawText(program, fontTextureID, currLine, 0.8, -0.1, glm::vec3(x, -19, 0));
		return;
	}

	int charCount = 0;
	stringstream ss(currLine);
	string word;
	string line;
	string line2;
	while (ss >> word) {
		charCount += word.size() + 1;
		if (charCount < 35) {
			line += word + " ";
		}
		else {
			line2 += word + " ";
			break;
		}
		
	}
	DrawText(program, fontTextureID, line, 0.8, -0.1, glm::vec3(x, -18,0));
	charCount = 0;
	while (ss >> word) {
		charCount += word.size() + 1;
		if (charCount < 35) {
			line2 += word + " ";
		}
		else {
			break;
		}

	}
	DrawText(program, fontTextureID, line2, 0.8, -0.1, glm::vec3(x, -19.5, 0));

}


void Util::DisplayText(ShaderProgram* program, GLuint fontTextureID, const Text& text, float xOffset) {

	if (text.isEnd) { return; }

	// display speaker
	if (text.getSpeaker() != "") {
		DrawText(program, fontTextureID, text.getSpeaker() + ": ", 0.8, -0.1, glm::vec3(1 + xOffset, -19, 0));
	}
	int x = text.getSpeaker() != "" ? 7 : 5;

	// display line
	string currLine = text.getCurLine();

	if (currLine.size() < 35) {
		DrawText(program, fontTextureID, currLine, 0.8, -0.1, glm::vec3(x + xOffset, -19, 0));
		return;
	}

	int charCount = 0;
	stringstream ss(currLine);
	string word;
	string line;
	string line2;
	while (ss >> word) {
		charCount += word.size() + 1;
		if (charCount < 35) {
			line += word + " ";
		}
		else {
			line2 += word + " ";
			break;
		}

	}
	DrawText(program, fontTextureID, line, 0.8, -0.1, glm::vec3(x + xOffset, -18, 0));
	charCount = 0;
	while (ss >> word) {
		charCount += word.size() + 1;
		if (charCount < 35) {
			line2 += word + " ";
		}
		else {
			break;
		}

	}
	DrawText(program, fontTextureID, line2, 0.8, -0.1, glm::vec3(x + xOffset, -19.5, 0));

}
