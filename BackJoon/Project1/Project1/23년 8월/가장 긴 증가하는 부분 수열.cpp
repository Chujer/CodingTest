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
	cin >> N;

	vector<pair<int, int>> DP(N + 1);
	
	int t;
	cin >> t;
	DP[1] = { 1, t };
	int answer = 0;

	for (int i = 2; i <= N; i++)
	{
		int temp;
		cin >> temp;
		if (i == 6)
			int b = 0;

		for (int j = i - 1; j >= 0; j--)
		{
			pair<int, int> tempP;
			if (temp > DP[j].second)
			{
				if (DP[j].first + 1 >= DP[i].first + 1)
				{
					DP[i] = {(DP[j].first + 1), temp};
					answer = max(answer, DP[i].first);
				}

				continue;
			}
		}
	}

	if (N == 1)
		answer = 1;
	
	cout << answer;
}