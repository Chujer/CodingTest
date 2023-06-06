#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> numbers;
	int lastNum = 0;

	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			numbers.push_back(i);
			lastNum = n % i;
			n = n / i;
			i = 1;
		}
	}

	for (int num : numbers)
	{
		cout << num << endl;
	}
	if (lastNum != 0)
		cout << lastNum;

}