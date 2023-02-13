#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> num;
	int c, m;
	cin >> c;
	cin >> m;
	int count = 0;

	for (int i = 0; i < c; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	for (int n : num)
	{
		if (n < m)
			cout << n << " ";
	}
}