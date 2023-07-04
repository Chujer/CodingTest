#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

void Cycle(vector<int>& arr, int turnRight)
{
	vector<int> temp;

	if (turnRight == 1)
	{
		temp.push_back(arr.back());

		for (int i = 0; i < arr.size() - 1; i++)
		{
			temp.push_back(arr[i]);
		}
		arr = temp;
	}
	else
	{
		for (int i = 1; i < arr.size(); i++)
		{
			temp.push_back(arr[i]);
		}
		temp.push_back(arr.front());

		arr = temp;
	}

	
}

int main()
{
	vector<vector<int>> arr;
	for (int i = 0; i < 4; i++)
	{
		string tempNum;
		cin >> tempNum;
		vector<int> temp;
		for (int j = 0; j < 8; j++)
		{
			temp.push_back(tempNum[j] - '0');
		}
		arr.push_back(temp);
	}

	int count;
	cin >> count;
	vector<vector<int>> cycleCount;

	for (int i = 0; i < count; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 2; j++)
		{
			int tempNum;
			cin >> tempNum;
			temp.push_back(tempNum);
		}
		cycleCount.push_back(temp);
	}

	map<int, int> cycleTarget;

		//2번째인덱스, 6번째 인덱스 비교해야함
	for (int i = 0; i < count; i++)
	{
		int cycleRot = cycleCount[i][1];
		int cycleIndex = cycleCount[i][0]-1;

		for (int j = cycleIndex; j > 0; j--)
		{
			cycleRot = cycleRot * -1;

			if (arr[j][6] != arr[j - 1][2])
			{
				cycleTarget[j - 1] += cycleRot;
				//Cycle(arr[j - 1], cycleRot);
			}
			else
				break;
		}

		cycleRot = cycleCount[i][1];

		for (int j = cycleIndex; j < arr.size() - 1; j++)
		{
			cycleRot = cycleRot * -1;

			if (arr[j][2] != arr[j + 1][6])
			{
				cycleTarget[j + 1] += cycleRot;
				//Cycle(arr[j + 1], cycleRot);
			}
			else
				break;
		}

		cycleRot = cycleCount[i][1];

		cycleTarget[cycleIndex] += cycleRot;
		//Cycle(arr[cycleIndex], cycleRot);

		for (pair<int, int> c : cycleTarget)
		{
			for (int i = 0; i < c.second; i++)
			{
				Cycle(arr[c.first], 1);
			}
			for (int i = c.second; i < 0; i++)
			{
				Cycle(arr[c.first], -1);
			}
		}
		cycleTarget.clear();
	}

	for (pair<int, int> c : cycleTarget)
	{
		for (int i = 0; i < c.second; i++)
		{
			Cycle(arr[c.first], 1);
		}
		for (int i = c.second; i < 0; i++)
		{
			Cycle(arr[c.first], -1);
		}
	}

	int sum = 0;

	if (arr[0][0] == 1)
		sum += 1;
	if (arr[1][0] == 1)
		sum += 2;
	if (arr[2][0] == 1)
		sum += 4;
	if (arr[3][0] == 1)
		sum += 8;


	cout << sum;
}
