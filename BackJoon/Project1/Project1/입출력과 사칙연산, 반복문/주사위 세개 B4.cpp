#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;
	int num[3];


	cin >> num[0];
	cin >> num[1];
	cin >> num[2];

	sort(num, num + 3);

	if (num[0] == num[1] && num[0] == num[2])
		answer = (num[0] * 1000) + 10000;
	else if (num[1] == num[0] || num[1] == num[2])
		answer = num[1] * 100 + 1000;
	else
		answer = num[2] * 100;


	cout << answer;


	return 0;
}