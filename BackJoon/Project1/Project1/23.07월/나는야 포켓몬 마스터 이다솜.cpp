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

	int N, M;
	cin >> N >> M;

	map<string, int> pokemonNames;
	map<int, string> pokemonNums;

	for (int i = 1; i <= N; i++)
	{
		string name;
		cin >> name;
		pokemonNames.insert(make_pair(name, i));
		pokemonNums.insert(make_pair(i, name));
	}

	for (int i = 0; i < M; i++)
	{
		string name;
		int num;
		cin >> name;
		if (name[0] >= '0' && name[0] <= '9')
		{
			num = stoi(name);
		}

		if (pokemonNames[name] != 0)
			cout << pokemonNames[name] << "\n";
		else
			cout << pokemonNums[num] << "\n";
	}
}