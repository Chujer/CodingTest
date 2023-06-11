#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	int minX, minY, maxX = -10000, maxY = -10000;
	int count;
	int answer;
	cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		int tempX, tempY;
		cin >> tempX >> tempY;

		if (i == 0)
		{
			minX = tempX;
			minY = tempY;
		}

		if (minX > tempX)
			minX = tempX;
		else if (maxX < tempX)
			maxX = tempX;

		if (minY > tempY)
			minY = tempY;
		else if (maxY < tempY)
			maxY = tempY;
	}

	answer = abs(maxX - minX) * abs(maxY - minY);

	cout << answer;
}