#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num[6];

	cin >> num[0];
	cin >> num[1];

	if (num[0] == 0)
		num[0] = 24;

	int time = num[0] * 60 + num[1] - 45;

	int h = time / 60;
	int m = time % 60;


	if (h == 24)
		h = 0;

	cout << h << " " << m;

	return 0;
}