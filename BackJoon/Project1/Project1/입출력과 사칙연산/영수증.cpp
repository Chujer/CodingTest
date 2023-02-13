#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;
	string s;
	int num[4];

	cin >> num[0];
	cin >> num[1];

	for (int i = 0; i < num[1]; i++)
	{
		cin >> num[2];
		cin >> num[3];
		answer += num[2] * num[3];

	}
	if (answer == num[0])
		cout << "Yes";
	else
		cout << "No";

	return 0;
}