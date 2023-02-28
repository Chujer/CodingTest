#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a = 0;
	cin >> a;
	int origin = a;
	int temp;
	int temp1 = 0;
	int temp2 = 0;
	int count = 0;

	do
	{
		temp1 = a / 10;
		if (a < 10)
			temp1 = 0;

		temp2 = a % 10;
		
		temp = temp1 + temp2;
		a = (temp2 * 10) + (temp % 10);


		count++;
	} while (origin != a);
	cout << count;

}