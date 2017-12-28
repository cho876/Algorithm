/**
	Recursive invocation algorithm for finding words in Vogel game board
*/

#include <iostream>
#include <string>

using namespace std;

char** createMap(int y, int x);
bool hasWord(int y, int x, const string& word);
bool inRange(int y, int x);

char** map;
int mapX, mapY;
int dx[] = { -1,-1,-1,1,1,1,0,0 };
int dy[] = { -1,0,1,-1,0,1,-1,1 };
string word;

int main() {
	cout << "Map Size: ";
	cin >> mapY >> mapX;

	map = createMap(mapY, mapX);

	cout << "Words you're looking for? ";
	cin >> word;

	int startX, startY;
	cout << "Starting Position(x,y): ";
	cin >> startX >> startY;

	if (hasWord(startY, startX,word))
		cout << "Found" << endl;
	else
		cout << "No Found" << endl;
	
	return 0;
}

/**
	Create Vogel Map
	
	param 1: map SIze(Row)
	param 2: map Size(Col)
*/
char** createMap(int y, int x) {
	map = new char*[y];

	for (int i = 0; i < y; i++)
		map[i] = new char[x];

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++)
			cin >> map[i][j];
	}
	return map;
}

/**
	Function that determines if a word exists

	param 1: current Pos (Row)
	param 2: current Pos (Col)
	param 3: The word you are looking for
*/
bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x))
		return false;
	if (map[y][x] != word[0])
		return false;
	if (word.size() == 1)
		return true;

	cout << "Founded pos: (" << x << ", " << y << ")" << endl;
	int nextX, nextY;
	for (int dir = 0; dir < 8; dir++) {
		nextY = y + dy[dir];
		nextX = x + dx[dir];
		if (hasWord(nextY, nextX, word.substr(1)))
			return true;
	}
	return false;
}

/**
	Function that determines Whether the current position is outside the map's position range

	param 1: current Position (Row)
	param 2: current Position (Col)
*/
bool inRange(int y, int x) {
	if (y >= mapY || x >= mapX)
		return false;
	return true;
}