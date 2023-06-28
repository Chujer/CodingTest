#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

void Cuts(vector<vector<int>> bord, map<string, int>& answer)
{
	if (bord.size() == 1)
	{
		if (bord[0][0] == 0)
			answer["white"]++;
		else if (bord[0][0] == 1)
			answer["blue"]++;
		return;
	}

	vector<vector<vector<int>>> cutBord(4);

	int count = 0;
	int colorCount = 0;

	for (int c = 0; c < 2; c++)
	{
		for (int d = 0; d < 2; d++)
		{
			colorCount = 0;
			for (int i = 0; i < bord.size() / 2; i++)
			{
				vector<int> temp;
				for (int j = 0; j < bord.size() / 2; j++)
				{
					int tempNum = bord[((c % 2) * bord.size() / 2) + i][((d % 2) * bord.size() / 2) + j];
					colorCount += tempNum;
					temp.push_back(tempNum);
				}
				cutBord[count].push_back(temp);
			}
			if (colorCount == 0)
				answer["white"]++;
			else if (colorCount == cutBord[count].size() * cutBord[count].size())
				answer["blue"]++;
			else
				Cuts(cutBord[count], answer);
			count++;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int CheckNum = 0;
	map<string,int> answer;

	vector<vector<int>> bord;

	for (int i = 0; i < N; i++)
	{
		vector<int> num;
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			num.push_back(temp);
			CheckNum += temp;
		}

		bord.push_back(num);
	}
	if (CheckNum == 0 )
	{
		cout << 1 << endl << 0;
		return 0;
	}
	else if (CheckNum == bord.size() * bord.size())
	{
		cout << 0 << endl << 1;
		return 0;
	}

	Cuts(bord, answer);

	cout << answer["white"] << endl << answer["blue"];
}