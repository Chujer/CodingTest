#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;
	string s;
	int num[3];


	cin >> num[0];

	for (int i = 0; i < num[0]; i++)
	{
		cin >> num[1];
		cin >> num[2];
		cout << num[1] + num[2] << endl;
	}



	return 0;
}