#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;
	string s;
	int num[3];
	int a = 1;

	cin >> num[0];

	for (int i = 0; i < num[0]; i++)
	{
		answer += a;
		a++;
	}

	cout << answer;

	return 0;
}