#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

void DFS(vector<vector<int>> arr, int x, int y)
{
	int dirLeft[2] = { -1,-1 };
	int dirRight[2] = { +1,-1 };
	int i = 0;
	while (true)
	{
		int checkLeft[2] = { x + (dirLeft[0] * i), y + (dirLeft[1] * i) };
		int checkRight[2] = {x + (dirRight[0] * i), y + (dirRight[1] * i)};

		if (checkLeft[0] < 0 || checkLeft[1] < 0 || checkRight[1] < 0)
			return;
		else if (checkRight[0] >= arr.size())
			return;

		if (arr[x + checkLeft[0]][y + checkLeft[1]] == -1 || arr[x + checkRight[0]][y + checkRight[1]] == -1)
			return;

		DFS(arr, x +1, y);
		i++;
	}
}

int main()
{
	int N;
	cin >> N;
	
	if (N == 1)
		cout << 1;
	else if (N < 4)
		cout << 0;

	vector<vector<int>> arr;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			temp.push_back(0);
		}
		arr.push_back(temp);
		temp.clear();
	}

}