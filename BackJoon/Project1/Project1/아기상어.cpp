#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct SharkData
{
	int size;
	int x;
	int y;
};

int Search(vector<vector<int>> boarder, SharkData sharkData)
{
	map<vector<int, int>, int> temp;
	int time = 1;

	for (int i = 0; i < 4; i++)
	{
		if (boarder[sharkData.x ][sharkData.y + 1] < sharkData.size && temp.find({ sharkData.x , sharkData.y + 1 }) == temp.end())
		{
			Search(boarder, sharkData);
		}
	}
}

int main()
{
	int board;
	int time = 0;
	
	cin >> board;

	

}