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

	int N, M;
	cin >> N >> M;

	vector<vector<int>> DP(M+1, vector<int>(N+1, 0));

	for (int i = 1; i <= M; i++)
	{
		int day, page;
		cin >> day >> page;

		for (int j = 1; j <= N; j++)
		{
			if (j - day >= 0)
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - day] + page);
			else
				DP[i][j] = DP[i - 1][j];
		}
	} 
	cout << DP[M][N];
}