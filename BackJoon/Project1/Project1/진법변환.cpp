#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string num;
	int binary;

	long long answer = 0;

	cin >> num;
	cin >> binary;

	int digits = 1;
	reverse(num.begin(), num.end());

	for (char n : num)
	{
		long long number = 0;
	
		if (n >= 'A' && n <= 'Z')
		{
			number = n - 'A' + 10;
		}
		else
			number = n - '0';

		number *= digits;
		answer += number;

		digits *= binary;
	}

	cout << answer;

	return 0;
}