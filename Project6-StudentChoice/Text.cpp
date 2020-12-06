#include "Text.h"

using namespace std;

Text::Text() {}
Text::Text(const vector<string>& epi, const string& who) : episode(epi), speaker(who) {}

const string& Text::getSpeaker() const {
	return speaker;
}

void Text::nextLine() {
	if (currLineIndex < episode.size()) {
		currLineIndex++;
	}
	if (currLineIndex >= episode.size()) { isEnd = true; }

}

const string& Text::getCurLine() const {
	return episode[currLineIndex];
}