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
	
	int DP[5000];

	DP[1] = -1;
	DP[2] = -1;
	DP[3] = 1;
	DP[4] = -1;
	DP[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		int temp = DP[i - 3] + 1;
		int temp2 = DP[i - 5] + 1;

		if (temp == 0 && temp2 == 0)
			DP[i] = -1;
		else if (temp == 0)
			DP[i] = temp2;
		else if (temp2 == 0)
			DP[i] = temp;
		else
			DP[i] = min(temp, temp2);
	}

	cout << DP[N];
}