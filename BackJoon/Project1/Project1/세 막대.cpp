#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int temp;
	vector<int> s;
	int maxIndex = 0;
	int maxSize;
	int min = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		s.push_back(temp);
		if (s.size() > 0 && temp > s[maxIndex])
			maxIndex = i;
	}

	maxSize = s[maxIndex];
	s.erase(s.begin() + maxIndex);
	for (int size : s)
		min += size;

	if (maxSize >= min)
		maxSize = min-1;

	cout << maxSize + min;
}