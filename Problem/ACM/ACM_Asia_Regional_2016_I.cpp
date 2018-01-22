#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
	char dir;
};

struct Command {
	string cmd;
	int spot;
};

Point recur(Point src, vector<Command> v_command, int index);
void changeDir(Point& curSrc, vector<Command> v_command, int index);
void moveSrc(Point& curSrc, vector<Command> v_command, int index);

int mapX;
int mapY;
int total_cmd;

int main()
{
	int length_of_one_side;

	cin >> length_of_one_side >> total_cmd;
	
	Point src;
	src.x = 0;
	src.y = 0;
	src.dir = 'e';

	mapX = mapY = length_of_one_side;
	vector<Command> v_command;

	Command tmp_cmd;
	string tmp_order;
	int tmp_move;
	for (int i = 0; i < total_cmd; i++) {
		cin >> tmp_order >> tmp_move;

		tmp_cmd.cmd = tmp_order;
		tmp_cmd.spot = tmp_move;
		v_command.push_back(tmp_cmd);
	}

	Point result = recur(src, v_command, 0);
	if (result.x == -99999 && result.y == -99999)
		cout << "-1" << endl;
	else
		cout << result.x << " " << result.y << endl;
	
	return 0;
}

Point recur(Point src, vector<Command> v_command, int index) {
	if (index >= total_cmd)
		return src;
	else {
		if (v_command[index].cmd == "MOVE")
			moveSrc(src, v_command, index);
		else
			changeDir(src, v_command, index);


		if (src.x < 0 || src.y < 0 || src.x >= mapX || src.y >= mapY) {
			src.x = -99999;
			src.y = -99999;
			return src;
		}
		return recur(src, v_command, index + 1);
	}
}

void moveSrc(Point& curSrc, vector<Command> v_command, int index) {
	if (curSrc.dir == 'e')
		curSrc.x += v_command[index].spot;
	else if (curSrc.dir == 'w')
		curSrc.x -= v_command[index].spot;
	else if (curSrc.dir == 'n')
		curSrc.y += v_command[index].spot;
	else
		curSrc.y -= v_command[index].spot;
}

void changeDir(Point& curSrc, vector<Command> v_command, int index) {
	if (v_command[index].spot == 0) {   // Rotate 90 degrees to the left
		if (curSrc.dir == 'e')
			curSrc.dir = 'n';
		else if (curSrc.dir == 'n')
			curSrc.dir = 'w';
		else if (curSrc.dir == 'w')
			curSrc.dir = 's';
		else
			curSrc.dir = 'e';
	}
	else {		 // Rotate 90 degrees to the right
		if (curSrc.dir == 'e')
			curSrc.dir = 's';
		else if (curSrc.dir == 'n')
			curSrc.dir = 'e';
		else if (curSrc.dir == 'w')
			curSrc.dir = 'n';
		else
			curSrc.dir = 'w';
	}
}