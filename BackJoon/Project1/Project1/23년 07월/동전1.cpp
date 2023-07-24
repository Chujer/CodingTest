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

int DP[10001];


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	vector<int> coins(N);

	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	
	for (int i = 0; i <= K; i += coins.front())
	{
		DP[i]++;
	}

	for (int c = 1; c < coins.size(); c++)
	{
		int a = 0;
		for (int i = coins[c]; i <= K; i++)
		{
			DP[i] += DP[i - coins[c]];
		}
	}

	cout << DP[K];
}