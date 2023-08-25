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

int dirx[4] = { 0, -1, 0, 1 };
int diry[4] = { -1, 0, 1, 0 };
int answer = 0;
vector<int> group;
queue<pair<int, int>> que;

void BFS(vector<vector<int>> arr, vector<vector<int>>& check, pair<int,int> start)
{
	if (check[start.second][start.first] == 0 && arr[start.second][start.first] == 1)
	{
		answer++;
		group.push_back(1);
		check[start.second][start.first] = 1;
	}

	if (arr[start.second][start.first] == 1)
	{	/*cout << "===========================================\n";
			for (int i = 0; i < check.size(); i++)
			{
				for (int j = 0; j < check.size(); j++)
				{
					cout << check[i][j] << " ";
				}
				cout << endl;
			}*/
		for (int i = 0; i < 4; i++)
		{
			int newX = dirx[i] + start.first;
			int newY = diry[i] + start.second;

			if (newX < 0 || newX >= arr.size() || newY < 0 || newY >= arr.size())
				continue;

			if (check[newY][newX] != 0)
				continue;

			if (arr[newY][newX] == 0)
				continue;

			if (group.size() < answer)
			{
			}
			else
				group[answer-1]++;

			que.push({ newX, newY });

			check[newY][newX] = 1;

		
		}
		if (!que.empty())
		{
			pair<int, int> temp;
			temp = que.front();
			que.pop();
			BFS(arr, check, temp);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> arr(N , vector<int>(N));
	vector<vector<int>> check(N , vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char temp;
			cin >> temp;
			arr[i][j] = temp - '0';
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			BFS(arr, check, { j,i });
		}
	}

	sort(group.begin(), group.end());

	cout << group.size() << "\n";
	for (int i : group) 
	{
		cout << i << "\n";
	}
}