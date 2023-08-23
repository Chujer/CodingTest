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

	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> board(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char c;
			cin >> c;
			if (c == 'B')
				board[i][j] += 1;
			else if(c == 'W')
				board[j][i] += -1;
		}
	}
	int a = 0;
}