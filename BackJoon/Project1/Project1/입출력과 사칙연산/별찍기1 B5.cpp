#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a;

	cin >> a;
	int count = 1;

	for (int i = 0; i < a; i++)
	{
		for(int j =0; j<count; j++)
			cout << "*";
		cout << endl;
		count++;
	}


	return 0;
}