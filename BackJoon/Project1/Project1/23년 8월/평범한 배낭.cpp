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

	int N, K, W, V;

	cin >> N >> K;

	vector<vector<int>> DP(101, vector<int>(100001,0));
	
	for (int i = 1; i <= N; i++)
	{
		cin >> W >> V;
		
		for (int j = 1; j <= K; j++)
		{
			if (DP[i][W] <= V)
				DP[i][W] = V;
			if (j >= W)
			{
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W] + V);
			}
			else
				DP[i][j] = DP[i - 1][j];
		}
		
	}

	cout << DP[N][K];
}