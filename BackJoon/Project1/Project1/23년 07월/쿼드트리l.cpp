#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

void QuadTree(vector<vector<int>> arr)
{	cout << "(";
	int count = 0;
	vector<vector<int>> temp;

	if (arr.size() == 1)
	{
		cout << arr[0][0];
		return;
	}

	int tempX,tempY;
	for (int beginY = 0; beginY < 2; beginY++)
	{
		for (int beginX = 0; beginX < 2; beginX++)
		{
			tempX = (beginX * (arr.size() / 2));
			tempY = (beginY * (arr.size() / 2));

			for (int i = 0; i < arr.size() / 2; i++)
			{
				vector<int> tempArr;
				for (int j = 0; j < arr.size() / 2; j++)
				{
					count += arr[tempY + i][tempX + j];
					tempArr.push_back(arr[tempY + i][tempX + j]);
				}
				temp.push_back(tempArr);
			}

			if (count == pow(temp.size(), 2))
				cout << 1;
			else if (count == 0)
				cout << 0;
			else
			{
				QuadTree(temp);
			}
			
			count = 0;
			temp.clear();
		}
	}

	

	cout << ")";
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> bord;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		vector<int> tempArr;
		string temp;
		cin >> temp;
		for (char c : temp)
		{
			tempArr.push_back(c-'0');
			count += c-'0';
		}
		bord.push_back(tempArr);
	}
	if (count == N * N)
		cout << 1;
	else if (count == 0)
		cout << 0;
	else
		QuadTree(bord);
}