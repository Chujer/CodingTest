#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <unordered_map>

using namespace std;

void DFS(vector<unordered_map<int, int>> arr, int N, int count, int& minAnswer, vector<int> team, map<vector<int>, int> Check)
{
	if (minAnswer == 0)
		return;

	vector<int> tempTeam;


	if (team.size() < N / 2)
	{
		tempTeam.assign(team.begin(), team.end());
		/*for (int i : team)
			tempTeam.push_back(i);*/
		tempTeam.push_back(count);
		for (int i = count+1; i < N; i++)
		{
			DFS(arr, N, i, minAnswer, tempTeam, Check);
		}
	}

	if (Check[tempTeam] != 0)
		return;
	Check[tempTeam]++;
	tempTeam.assign(team.begin(), team.end());

	if (tempTeam.size() == N / 2)
	{
		vector<int> otherTeam;
		int teamPower = 0;
		int otherTeamPower = 0;

		for (int i = 0; i < N; i++)
		{
			if (find(tempTeam.begin(), tempTeam.end(), i) == tempTeam.end())
				otherTeam.push_back(i);
		}

		for (int i = 0; i < tempTeam.size(); i++)
		{
			for (int j = 0; j < tempTeam.size(); j++)
			{
				if (i == j)
					continue;
				teamPower += arr[tempTeam[i]][tempTeam[j]];
			}
		}
		for (int i = 0; i < otherTeam.size(); i++)
		{
			for (int j = 0; j < otherTeam.size(); j++)
			{
				if (i == j)
					continue;
				otherTeamPower += arr[otherTeam[i]][otherTeam[j]];
			}
		}
		int powerGap = abs(teamPower - otherTeamPower);

		if (minAnswer > powerGap)
		{
			minAnswer = powerGap;
		}
		return;
	}


	return;
}

int main()
{
	int N;
	cin >> N;

	vector<unordered_map<int,int>> arr;
	vector<int> team;
	map<vector<int>, int> Check;
	int minAnswer = 0;

	for (int i = 0; i < N; i++)
	{
		unordered_map<int, int> temparr;
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			temparr.insert(make_pair(j, temp));
			minAnswer += temp;
		}
		arr.push_back(temparr);
	}

	for (int i = 0; i < N; i++)
	{
		DFS(arr, N, i, minAnswer, team,Check);
	}

	cout << minAnswer;
}