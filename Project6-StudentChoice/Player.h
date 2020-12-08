#pragma once

#include "Entity.h"
#include <SDL_mixer.h>

class Player : public Entity {

public:
	Player(GLuint textID, glm::vec3 position);

	void ProcessPlayerInput(SDL_Event& event);

	void CheckCollisionsX(Map* map);
	void CheckCollisionsY(Map* map);

	void Update(float deltaTime, const std::vector<Entity*>& entitySets, Map* map);

	void talkedToMangeta();
	
	void copyProgress(Player* prevPlayer);
	InteractionType onWhat = InteractionType::NONE;
	InteractionType interactionType = InteractionType::NONE;
	bool hasOrb = false;
	bool isDead = false;
	bool isInteracting = false;
	bool advanceStage = false;
private:
	bool isInvincible = false;
	int magentaTalks = 0;
	
	Mix_Chunk* contactSfx;
	Mix_Chunk* alertSfx;

};