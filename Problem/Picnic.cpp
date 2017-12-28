/**
	An algorithm that calculates the number of ways that each pair of students can pair with each other, given whether or not they are friends.
*/

#include <iostream>

using namespace std;

bool** initRelation(int students);
void makeRelation(bool**& areFriends, int pairs);
int countPair(bool**& areFriends, bool*& taken, int students);


int main()
{
	int cases;
	cout << "The number of Cases: ";
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int number_of_students;
		int number_of_pairs;

		cout << "The number of (Students & Pairs): ";
		cin >> number_of_students >> number_of_pairs;

		bool* taken = new bool[number_of_students];  // Determine whether i - th student has found a partner
		for (int j = 0; j < number_of_students; j++)
			taken[j] = false;

		bool** areFriends = initRelation(number_of_students);  // Determine whether you are friends with each other
		makeRelation(areFriends, number_of_pairs);

		int result = countPair(areFriends, taken, number_of_students);  // The number of ways that all students can be mated only with friends
		cout << "Result: " << result << endl;
	}
}

/**
	Counting the number of ways that all students can be mated only with friends (Recursive)

	param 1: Determine whether you are friends with each other
	param 2: Determine whether i - th student has found a partner
	param 3: The number of students
*/
int countPair(bool**& areFriends, bool*& taken, int students) {
	int firstFree = -1;

	for (int i = 0; i < students; i++)
		if (!taken[i]) {
			firstFree = i;
			break;
		}

	if (firstFree == -1)
		return 1;

	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < students; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPair(areFriends, taken, students);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

/**
	Creating Relationships Between Students

	param 1: Determine whether you are friends with each other
	param 2: The number of Pairs
*/
void makeRelation(bool**& areFriends, int pairs) {
	int friend1, friend2;
	for (int j = 0; j < pairs; j++) {
		cin >> friend1 >> friend2;
		areFriends[friend1][friend2] = true;
		areFriends[friend2][friend1] = true;
	}
}

/**
	Initiallize Relation

	param: The number of Students
*/
bool** initRelation(int students) {
	bool** areFriends = new bool*[students];
	for (int i = 0; i < students; i++)
		areFriends[i] = new bool[students];

	for (int i = 0; i < students; i++) {
		for (int j = 0; j < students; j++)
			areFriends[i][j] = false;
	}
	return areFriends;
}