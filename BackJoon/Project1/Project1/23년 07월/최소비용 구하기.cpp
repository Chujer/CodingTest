#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

void DFS(vector<vector<int>> arr, int endPos, int pos, int curPower,int& minPower)
{
	if (pos == endPos)
	{
		if (curPower < minPower)
			minPower = curPower;
	}

	for (vector<int> a : arr)
	{
		if (a[0] == pos)
		{
			curPower += a[2];
			if (curPower > minPower)
				return;

			DFS(arr, endPos, a[1], curPower, minPower);
			curPower -= a[2];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<int,vector<vector<int>>> buses;
	//vector<vector<int>> bus(M);

	int answer = 0;

	for (int i = 0; i < M; i++)
	{
		vector<int> temp(3);
		cin >> temp[0] >> temp[1] >> temp[2];
		answer += temp[2];
		buses[temp[0]].push_back(temp);
	}
	int start, end;
	cin >> start >> end;

	int DP[1001];
	
	fill_n(DP, 1001, 10000);

	DP[start] = 0;

	vector<int> curPos;
	vector<int> nextPos;


	for (vector<int> a : buses[start])
	{
		if (a[2] < DP[a[1]])
		{
			DP[a[1]] = a[2];
			curPos.push_back(a[1]);
			nextPos.push_back(a[1]);
		}
	}

	for (int i = 0; i < curPos.size(); i++)
	{
		if(i == 0)
			nextPos.clear();

		for (vector<int> a : buses[curPos[i]])
		{
			if (a[2] + DP[a[1]] < DP[a[1]])
			{
				DP[a[1]] = a[2] + DP[a[1]];
			}
			nextPos.push_back(a[1]);
		}
		if(i == curPos.size() - 1)
			curPos = nextPos;
	}


	cout << answer;
}