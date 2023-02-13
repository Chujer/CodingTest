#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> num;
	int c;
	cin >> c;
	int min = 1000000, max = 0;

	for (int i = 0; i < c; i++)
	{
		int temp;
		cin >> temp;
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	}


	cout << min <<" "<< max;
	
}