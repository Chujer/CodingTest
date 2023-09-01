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

int DP[1001][1001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	int sizeA = a.size();

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
				DP[i + 1][j + 1] = DP[i][j] + 1;
			else
				DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j+1]);
		}
	}

	cout << DP[a.size()][b.size()];
}