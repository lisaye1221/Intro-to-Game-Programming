#include "Text.h"

using namespace std;

Text::Text() {
	episode = { "" };
	textSfx = Mix_LoadWAV("assets/audio/text.wav");
	isEnd = true;
}
Text::Text(const vector<string>& epi, const string& who, bool isQuestion) : episode(epi), speaker(who), isQuestion(isQuestion) {
	textSfx = Mix_LoadWAV("assets/audio/text.wav");
	Mix_VolumeChunk(textSfx, MIX_MAX_VOLUME / 3);
}

Text::~Text() {
	Mix_FreeChunk(textSfx);
}

bool Text::getIsQuestion() const {
	return isQuestion;
}

const string& Text::getSpeaker() const {
	return speaker;
}

void Text::nextLine() {
	if (currLineIndex < episode.size() && !isEnd) {
		currLineIndex++;
		Mix_PlayChannel(-1, textSfx, 0);
	}
	if (isQuestion && episode.size() == 1) { isEnd = true; }
	if (isQuestion && currLineIndex >= episode.size() - 1) { isEnd = true; }
	if (!isQuestion && currLineIndex >= episode.size()) { isEnd = true; }

}

string Text::getCurLine() const {
	if (isQuestion && currLineIndex >= episode.size() - 1) { return episode.back(); }
	if (!isQuestion && currLineIndex >= episode.size()) { return ""; }
	return episode[currLineIndex];
}