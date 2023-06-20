#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> movies;
	string checkString;
	for (int i = 666; movies.size() != N; i++)
	{
		checkString = to_string(i);

		if (checkString.find("666") == string::npos)
			continue;

		movies.push_back(i);

	}
	cout << movies.back();
}
