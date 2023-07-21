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
	map<int, vector<vector<char>>> stars;

	int N;
	cin >> N;
	
	int count = 0;
	while (N != 1)
	{
		N /= 3;
		count++;
	}

	vector<vector<char>> sample =
	{
		{'*','*','*'},
		{'*',' ','*'},
		{'*','*','*'}
	};

	stars[1] = sample;


	for (int c = 2; c <= count; c++)
	{
		stars[c].resize(stars[c - 1].size() * 3);
		for (int i = 0; i < stars[c].size(); i++)
		{
			int testNum = stars[c].size() / 3;
			stars[c][i].resize(stars[c - 1].size() * 3);

			for (int j = 0; j < stars[c].size(); j++)
			{
				if (j >= testNum && testNum + testNum > j)
				{
					if (i >= testNum && testNum + testNum > i)
					{
						stars[c][i][j] = ' ';
						continue;
					}
				}
				stars[c][i][j] = stars[c - 1][i % stars[c-1].size()][j % stars[c - 1].size()];
			}
		}
	}

	for (int i = 0; i < stars[count].size(); i++)
	{
		for (int j = 0; j < stars[count].size(); j++)
		{
			cout << stars[count][i][j];
		}
		cout << endl;
	}
}