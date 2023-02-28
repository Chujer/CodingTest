#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int a;
	cin >> a;

	int count = 0;
	count = a / 4;
	if (a % 4 != 0)
		count++;

	for(int i = 0; i<count; i++)
	{
		cout << "long ";
	}
	cout << "int";

	return 0;
}