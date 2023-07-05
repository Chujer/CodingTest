#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <map>

using namespace std;

int main()
{
	map<string, bool> people;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		string g;
		cin >> temp >> g;
		if (g == "enter")
			people[temp] = true;
		else
			people[temp] = false;
	}
	vector<string> temp;

	for (pair<string, bool> p : people)
	{
		if (p.second == true)
			temp.push_back(p.first);
	}

	for (int i = temp.size() - 1; i >= 0; i--)
		cout << temp[i] << "\n";

}