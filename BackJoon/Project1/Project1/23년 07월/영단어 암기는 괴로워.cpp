#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;


bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second > b.second)
	{
		return true;
	}
	else if (a.second == b.second)
	{
		if (a.first.size() > b.first.size())
		{
			return true;
		}
		else if (a.first.size() == b.first.size())
		{
			if (a.first < b.first)
				return true;
		}
	}
	return false;
}

void Soloution(map<string, int>& mArr)
{
	vector<pair<string, int>> v;

	for (auto m : mArr)
	{
		v.push_back(m);
	}

	sort(v.begin(), v.end(), cmp);

	for (pair<string, int> a : v)
	{
		cout << a.first << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<string, int> mArr;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		if (temp.size() >= M)
			mArr[temp]++;
	}

	Soloution(mArr);
}