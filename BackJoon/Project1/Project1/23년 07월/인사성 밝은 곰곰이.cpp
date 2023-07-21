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

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	map<string, int> people;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s != "ENTER")
		{
			people[s] = 1;
		}
		else
		{
			count += people.size();
			people.clear();
		}
	}
	count += people.size();

	cout << count;
}