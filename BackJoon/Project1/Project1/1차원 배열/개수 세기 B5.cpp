#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> num;
	int c;
	cin >> c;
	int count=0;

	for (int i = 0; i < c; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	cin >> c;

	for (int n : num)
	{
		if (n == c)
			count++;
	}
	cout << count;
}