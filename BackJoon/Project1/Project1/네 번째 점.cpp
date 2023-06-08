#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	int x, y;
	map<int, int> mX;
	map<int, int> mY;

	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		mX[x]++;
		mY[y]++;
	}

	for (pair<int, int> n : mX)
	{
		if (n.second == 1)
			cout << n.first << " ";
	}
	for (pair<int, int> n : mY)
	{
		if (n.second == 1)
			cout << n.first;
	}

}