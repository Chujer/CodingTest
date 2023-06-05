#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	int number;
	int answer = 0;

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> number;

		if (number == 2 || number == 3)
		{
			answer++;
			continue;
		}

		for (int i = 2; i < number; i++)
		{
			if (number % i == 0)
				break;
			if (i == number - 1)
				answer++;
		}

	}
	cout << answer;
}