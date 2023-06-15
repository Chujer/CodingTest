#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int DP[1000001] = { 0, };

int main()
{
	int N;
	int i = 4;
	int answer = 0;
	cin >> N;



	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;

	for(int i = 4; i <= N; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			DP[i] = min(DP[i / 3] + 1, min(DP[i / 2] + 1, DP[i - 1] + 1));
		}
		else if (i % 2 == 0)
		{
			DP[i] = min(DP[i - 1] + 1, DP[i / 2] + 1);
		}
		else if (i % 3 == 0)
		{
			DP[i] = min(DP[i - 1] + 1, DP[i / 3] + 1);
		}
		else
			DP[i] = DP[i - 1] + 1;
	}


	cout << DP[N];
}