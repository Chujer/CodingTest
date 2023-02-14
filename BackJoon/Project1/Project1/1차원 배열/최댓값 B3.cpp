#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> num;
	int c;
	c = 9;
	int max = 0;
	int index = 0;

	for (int i = 0; i < c; i++)
	{
		int temp;
		cin >> temp;
		if (temp > max)
		{
			max = temp;
			index = i;
		}
	}


	cout << max << endl << index + 1;

}