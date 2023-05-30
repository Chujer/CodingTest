#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<math.h>

using namespace std;

int main()
{
	int in;
	cin >> in;
	int answer;

	int plusCount = 2;

	for (int i = 0; i < in; i++)
	{
		plusCount += plusCount - 1;
	}

	answer = pow(plusCount,2);

	cout << answer;;

	return 0;
}