/**
	The 41st Annual ACM
		Asia Regional-Daejeon
		Nationwide Internet Competition
		Probelm L (Trucks)
*/

#include <iostream>

using namespace std;

struct Truck {
	int weight;
	int pos;
};

int main()
{
	int number_of_trucks; // Number of trucks
	int bridge_length;  // Bridge length
	int maximum_load;  // Maximum load

	cin >> number_of_trucks >> bridge_length >> maximum_load;

	Truck* truck = new Truck[number_of_trucks];

	for (int i = 0; i < number_of_trucks; i++) {
		cin >> truck[i].weight;
		truck[i].pos = 0;
	}

	int number_of_trucks_past = 0;  // Number of Trucks Past
	int cur = 0;                    // Current bus index
	int next = 0;                   // Next bus index
	int time = 0;                   // Elapsed time
	int current_load = 0;           //Current load

	while (number_of_trucks_past != number_of_trucks) {  // Until all the trucks pass the bridge
		while (truck[cur].pos < bridge_length) {  // Until the current truck passes the bridge
			time++;
			if (truck[cur].pos == 0) {  // When the current truck enters the bridge
				truck[cur].pos++;
				current_load += truck[cur].weight;
				next = cur + 1;
			}
			else if (truck[cur].pos != 0 && truck[next].weight + current_load <= maximum_load) {  // If you have already entered the bridge and an additional truck is available
				for (int j = cur; j <= next; j++)
					truck[j].pos++;
				current_load += truck[next].weight;
				next++;
			}
			else if (truck[cur].pos != 0 && truck[next].weight + current_load > maximum_load) {  // If you have already entered the bridge and no additional trucks can enter
				for (int j = 0; j < next; j++)
					truck[cur].pos++;
			}
		}
		current_load -= truck[cur].weight;  // Current load reduction as much as the weight of the truck that passed
		cur++;
		number_of_trucks_past++;
	}
	cout << time + 1 << endl;
}