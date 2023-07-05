#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <map>

using namespace std;

void Check(vector<vector<int>> arr, map<int, int>& answer)
{
	vector<vector<int>> tempArr;
	if (arr.size() == 1)
	{
		if (arr[0][0] ==1)
		{
			answer[1]++;
		}
		else if (arr[0][0] == -1)
		{
			answer[-1]++;
		}
		else if (arr[0][0] == 0)
		{
			answer[0]++;
		}
	}

	for (int beginY = 0; beginY < 3; beginY++)
	{
		for (int beginX = 0; beginX < 3; beginX++)
		{
			int count = 0;
			int first = -3;
			bool goCheck = false;
			for (int i = 0; i < arr.size() /3; i++)
			{
				vector<int> inTempArr;
				for (int j = 0; j < arr.size() / 3; j++)
				{
					int temp = arr[(beginY * arr.size() / 3)+ i][(beginX * arr.size() / 3) + j];

					if (i == 0 && j == 0)
						first = temp;

					if (first != -3 && first != temp)
						goCheck = true;

					count += temp;

					inTempArr.push_back(temp);
				}
				tempArr.push_back(inTempArr);				
			}


			if (count == pow(tempArr.size(), 2) && goCheck == false)
			{
				answer[1]++;
			}
			else if (count == -1 * pow(tempArr.size(), 2) && goCheck == false)
			{
				answer[-1]++;
			}
			else if (count == 0 && goCheck == false)
			{
				answer[0]++;
			}
			else if(goCheck == true)
			{
				Check(tempArr, answer);
			}
			tempArr.clear();
		}
	}
}

int main()
{
	int N;
	cin >> N;

	int count = 0;
	map<int, int> answer;
	answer.insert(make_pair(-1, 0));
	answer.insert(make_pair(0, 0));
	answer.insert(make_pair(1, 0));
	vector<vector<int>> arr;

	int first = -3;
	bool goCheck = false;

	for (int i = 0; i < N; i++)
	{
		vector<int> tempArr;
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			count += temp;

			if (i == 0 && j == 0)
				first = temp;

			if (first != -3 && first != temp)
				goCheck = true;

			tempArr.push_back(temp);
		}
		arr.push_back(tempArr);
	}

	if (count == pow(arr.size(), 2) && goCheck == false)
	{
		answer[1]++;
	}
	else if (count == -1 * pow(arr.size(), 2) && goCheck == false)
	{
		answer[-1]++;
	}
	else if (count == 0 && goCheck == false)
	{
		answer[0]++;
	}
	else if (goCheck == true)
	{
		Check(arr, answer);
	}

	for (pair<int, int> a : answer)
	{
		cout << a.second << "\n";
	}
}