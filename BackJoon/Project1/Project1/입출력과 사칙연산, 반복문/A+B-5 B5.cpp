#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a;
	int b;

	cin >> a;
	cin >> b;

	while (a != 0 && b != 0)
	{
		cout << a + b << endl;
		cin >> a;
		cin >> b;
	}


	return 0;
}