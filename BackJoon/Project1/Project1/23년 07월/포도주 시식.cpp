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

	int N;
	int arr[10002];
	int DP1[10002];
	int DP2[10002];
	int DP[10002];
	cin >> N;
	
	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
	}

	DP[1] = arr[1];
	DP[2] = arr[2] + arr[1];

	DP1[1] = arr[1];
	DP1[2] = arr[2] + arr[1];

	DP2[1] = arr[1];
	DP2[2] = arr[2] + arr[1];

	//DP1은 앞에 없을때
	//DP2는 앞에 있을때
	for (int i = 3; i < N + 1; i++)
	{
		DP1[i] = max(arr[i] + DP[i - 2], DP[i-1]);
		DP2[i] = max(arr[i] + arr[i-1] + DP[i - 3], DP[i-1]);

		DP[i] = max(DP1[i], DP2[i]);
	}

	cout << DP[N];
}