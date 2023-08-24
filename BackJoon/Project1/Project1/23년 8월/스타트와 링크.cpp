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

int N;
int answer = 0;

void DFS(vector<vector<int>> arr, vector<int> index, int temp, int teamCount)
{
	index[temp] = 1;
	teamCount++;

	if (teamCount == N / 2)
	{
		vector<int> start;
		vector<int> link;
		int startScore = 0;
		int linkScore = 0;

		for (int i = 1; i < index.size(); i++)
		{
			if (index[i] != 1)
			{
				link.push_back(i);
			}
			else
				start.push_back(i);
		}

		for (int i = 0; i < link.size() - 1; i++)
		{
			for (int j = i + 1; j < link.size(); j++)
			{
				startScore += arr[start[i]][start[j]] + arr[start[j]][start[i]];
				linkScore += arr[link[i]][link[j]] + arr[link[j]][link[i]];
			}
		}

		if (abs(startScore - linkScore) < answer)
			answer = abs(startScore - linkScore);

	}
	else
	{
		for (int i = temp + 1; i <= N; i++)
		{
			DFS(arr, index, i, teamCount);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<vector<int>> arr(N + 1, vector<int>(N + 1));
	vector<int> index(N+1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
			answer += temp;
		}
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	index.push_back(0); 
	//}
	for(int i = 1 ; i <= N/2; i++)
		DFS(arr, index, i, 0);

	cout << answer;
}