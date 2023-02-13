#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num[6];

	cin >> num[0];
	cin >> num[1];
	cin >> num[2];

	if (num[0] == 0)
		num[0] = 24;

	int time = num[0] * 60 + num[1] + num[2];

	int h = time / 60;
	int m = time % 60;

	h = h % 24;


	cout << h << " " << m;

	return 0;
}