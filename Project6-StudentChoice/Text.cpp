#include "Text.h"

using namespace std;

Text::Text() {}
Text::Text(const vector<string>& epi, const string& who) : episode(epi), speaker(who) {
	textSfx = Mix_LoadWAV("assets/audio/text.wav");
	Mix_VolumeChunk(textSfx, MIX_MAX_VOLUME / 3);
}

const string& Text::getSpeaker() const {
	return speaker;
}

void Text::nextLine() {
	if (currLineIndex < episode.size()) {
		currLineIndex++;
		Mix_PlayChannel(-1, textSfx, 0);
	}
	if (currLineIndex >= episode.size()) { isEnd = true; }

}

string Text::getCurLine() const {
	if (currLineIndex >= episode.size()) { return ""; }
	return episode[currLineIndex];
}