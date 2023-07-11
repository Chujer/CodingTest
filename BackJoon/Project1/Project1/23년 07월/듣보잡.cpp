#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> man;
	int N, M;
	vector<string> s;
	cin >> N >> M;

	for (int i = 0; i < N+M; i++)
	{
		string temp;
		cin >> temp;
		man[temp]++;
		if (man[temp] > 1)
			s.push_back(temp);
	}

	cout << s.size() << endl;

	sort(s.begin(), s.end());

	for (string name : s)
	{
		cout << name << endl;
	}

}