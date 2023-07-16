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

	if (N <= 2 && M >= 2)
	{
		cout << 2 << "\n";
	}
	if (N <= 3 && M >= 3)
	{
		cout << 3 << "\n";
	}

	for (int i = N; i < M + 1; i++)
	{
		for (int j = 2; j <= sqrt(i)+1; j++)
		{
			int temp = sqrt(i);
			if (i % j == 0)
				break;

			if (j == temp)
				cout << i << "\n";
		}
	}
}