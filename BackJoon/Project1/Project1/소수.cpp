#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int m, n;
	
	cin >> m;
	cin >> n;

	int sum = 0;
	int min = n;

	for (int i = m; i <= n; i++)
	{
		if (i == 2)
		{
			sum += i;
			min = i;
		}

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}

			if (j == i - 1)
			{
				sum += i;
				if (min > i)
					min = i;
			}
		}
	}
	if (sum == 0)
		cout << -1;
	else
	{
		cout << sum << endl;
		cout << min << endl;
	}
}