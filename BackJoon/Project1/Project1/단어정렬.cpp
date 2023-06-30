#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int compere(string a, string b)
{
	if (a.size() < b.size())
		return 1;
	else if (a.size() > b.size())
		return 0;
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] < b[i])
				return 1;
			else if (a[i] > b[i])
				return 0;
		}
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;

	vector<string> data;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		data.push_back(temp);
	}

	sort(data.begin(), data.end(), compere);

	vector<string> test;

	for (string d : data)
	{
		if (test.size() > 0 && d == test.back())
			continue;
		test.push_back(d);
	}

	for (string t : test)
	{
		cout << t << endl;
	}
}