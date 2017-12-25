/**
	The 41st Annual ACM
		Asia Regional-Daejeon
		ASIA Regional

		Probelm G (Percolation)
*/

#include "Maze.h"

using namespace std;

int main()
{
	Maze map;
	Point src, dst;
	int mapCol;
	int mapRow;

	cin >> mapRow >> mapCol;
	map.createMap(mapCol, mapRow);

	for (int i = 0; i < mapCol; i++) {  // All the topmost rows of the map
		src.row = 0;
		src.col = i;
		for (int j = 0; j < mapCol; j++) {  // All rows at the bottom of the map
			dst.row = mapRow - 1;
			dst.col = j;
			if (map.pathExist(src, dst)) {  // If the route is open from the start to the destination
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
