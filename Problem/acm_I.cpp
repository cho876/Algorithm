/**
		The 41st Annual ACM
			Asia Regional-Daejeon
			Nationwide Internet competition

		Probelm I (Q-Index)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool numExist(vector<int> citations, int number_of_papers_published);
void push_and_sort(vector<int>& citations, int number_of_papers_published);
bool is_zero(vector<int> citations);

int main()
{
	int number_of_papers_published;   // Number of papers published
	cin >> number_of_papers_published;

	vector<int> vector_number_of_citations;

	int tmp;
	for (int i = 0; i < number_of_papers_published; i++) {
		cin >> tmp;
		vector_number_of_citations.push_back(tmp);
	}
	sort(vector_number_of_citations.begin(), vector_number_of_citations.end(), greater<int>());


	int index_found;
	if (numExist(vector_number_of_citations, number_of_papers_published))     // If there are "published papers" in the quotation list
		index_found = find(vector_number_of_citations.begin(), vector_number_of_citations.end(), number_of_papers_published) - vector_number_of_citations.begin() + 1;

	else { 
		if (is_zero(vector_number_of_citations)) {   // When the number of citations is all "0"
			cout << 0 << endl;
			return 0;
		}
		else {
			push_and_sort(vector_number_of_citations, number_of_papers_published);
			index_found = find(vector_number_of_citations.begin(), vector_number_of_citations.end(), number_of_papers_published) - vector_number_of_citations.begin() + 1;
		}
	}
	cout << index_found << endl;
	return 0;
}

/**
	The number of "published papers" is the number in the number of citations per article.

	param 1: List of citations per article
	param 2: Number of papers published
*/
bool numExist(vector<int> citations, int number_of_papers_published)
{
	for (int i = 0; i < number_of_papers_published; i++) {
		if (citations[i] == number_of_papers_published)
			return true;
	}
	return false;
}

/**
	After adding the number of "published papers" in the list of citations per article &
	Sort functions in descending order

	param 1: List of citations per article
	param 2: Number of papers published
*/
void push_and_sort(vector<int>& citations, int number_of_papers_published) {
	citations.push_back(number_of_papers_published);
	sort(citations.begin(), citations.end(), greater<int>());
}


/**
	Whether the number of citations per each paper is 0 or not

	param : List of citations per article
*/
bool is_zero(vector<int> citations) {
	vector<int>::iterator v_iter = citations.begin();
	for (v_iter; v_iter != citations.end(); v_iter++) {
		if (*v_iter != 0)
			return false;
	}
	return true;
}