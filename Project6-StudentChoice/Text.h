#ifndef TEXT_H
#define TEXT_H

#include <SDL_mixer.h>
#include<vector>
#include<string>

class Text {
	// holds the text that will be display in one interaction
	std::vector<std::string> episode;
	// holds the name of the speaker
	std::string speaker;
	size_t currLineIndex = 0;
	Mix_Chunk* textSfx;
	bool isQuestion;
public:
	bool isEnd = false;
	~Text();
	Text();
	Text(const std::vector<std::string>& epi, const std::string&, bool isQuestion = false);

	bool getIsQuestion() const;
	const std::string& getSpeaker() const;
	void nextLine();
	std::string getCurLine() const ;
	

};

#endif // !TEXT_h

