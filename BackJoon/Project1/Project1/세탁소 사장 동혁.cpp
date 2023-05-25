#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	const int quarter = 25;
	const int dime = 10;
	const int nickel = 5;
	const int penny = 1;
	int caseCount = 0;
	vector<int> C;

	cin >> caseCount;

	for (int i = 0; i < caseCount; i++)
	{
		int temp;
		cin >> temp;
		C.push_back(temp);
	}

	for (int i : C)
	{
		if (i / quarter != 0)
		{
			cout << to_string(i / quarter) + ' ';
			i = i % quarter;
		}
		else
			cout << "0 ";
		if (i / dime != 0)
		{
			cout << to_string(i / dime) + ' ';
			i = i % dime;
		}
		else
			cout << "0 ";
		if (i / nickel != 0)
		{
			cout << to_string(i / nickel) + ' ';
			i = i % nickel;
		}
		else
			cout << "0 ";
		if (i / penny != 0)
		{
			cout << to_string(i / penny) + ' ';
			i = i % nickel;
		}
		else
			cout << "0 ";
		cout << endl;
	}

	return 0;
}