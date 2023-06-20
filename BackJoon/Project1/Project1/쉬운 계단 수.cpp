#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int answer = 0;

	int DP[101][10] = {0};

	for (int i = 1; i < 10; i++)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i < N+1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				DP[i][j] = DP[i - 1][j+1];
			}
			else if (j == 9)
			{
				DP[i][j] = DP[i - 1][j-1] ;
			}
			else
			{
				DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];
			}
			DP[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		answer += DP[N][i];
		answer %= 1000000000;
	}
	cout << answer;

}