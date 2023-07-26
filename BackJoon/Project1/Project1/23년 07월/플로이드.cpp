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

void Draw(vector<vector<int>> arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 1; j < arr.size(); j++)
		{
			if (j == 0)
				cout << i << " ";
			else
			{
				if (arr[i][j] == 10000000)
					cout << 0 << " ";
				else
					cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int MAX = 10000000;
	vector<vector<int>> arr(N+1, vector<int>(N+1, MAX));
	

	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if (arr[start][end] == 0 || arr[start][end] > cost)
		{
			arr[start][end] = cost;
		}
	}
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 1; j < arr.size() ; j++)
		{
			for (int r = 1; r < arr.size(); r++)
			{
				arr[j][r] = min(arr[j][r], arr[j][i] + arr[i][r]);
				if (j == r)
					arr[j][r] = 0;
			}
		}
	}

	Draw(arr);

}