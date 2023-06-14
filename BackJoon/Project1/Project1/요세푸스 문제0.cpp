#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main(int A[], int n)
{
	int N, K;
	int deathCount = 0;
	int index = -1;
	cin >> N >> K;

	vector<int> people;
	vector<int> answer;

	for (int i = 1; i<N+1; i++)
	{
		people.push_back(i);
	}

	while (people.size() != 0)
	{
		index = (index + K) % (people.size() );
		answer.push_back(people[index]);
		people.erase(people.begin() + index );
		index--;
	}

	cout << "<";

	for (int i =0; i< answer.size()-1; i++)
	{
		cout << answer[i] << ", ";
	}
	cout << answer.back() << ">";
}