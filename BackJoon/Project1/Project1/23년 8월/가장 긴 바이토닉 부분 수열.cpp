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

	vector<int> arr(N+1 + 2);
	vector<int> DP(N + 1);
	vector<int> DP2(N + 2);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N ; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (DP[i] < DP[j] + 1)
					DP[i] = DP[j] + 1;
			}
		}
	}
	for (int i = N; i >= 0; i--)
	{
		for (int j = N+1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				if (DP2[i] < DP2[j] + 1)
					DP2[i] = DP2[j] + 1;
;			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= N; i++)
	{
		int maxDP1 = 0;
		int maxDP2 = 0;
		int maxIndex = 0;
		for (int j = 1; j <= i; j++)
		{
			if (maxDP1 <= DP[j])
			{
				maxDP1 = max(maxDP1, DP[j]);
				maxIndex = j;
			}
		}
		for (int j = N; j > i; j--)
		{
			if(arr[j] != arr[maxIndex])
				maxDP2 = max(maxDP2, DP2[j]);
		}
		answer = max(maxDP1 + maxDP2, answer );
	}

	cout << answer;
}