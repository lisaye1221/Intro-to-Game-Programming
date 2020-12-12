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


bool Text::getIsQuestion() const {
	return isQuestion;
}

const string& Text::getSpeaker() const {
	return speaker;
}

bool Text::isAtEnd() const {
	return currLineIndex == episode.size();
}

void Text::nextLine() {
	if (currLineIndex < episode.size() && !isEnd && isQuestion) {
		currLineIndex++;
		Mix_PlayChannel(-1, textSfx, 0);
	}
	else if (currLineIndex < episode.size()) {
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