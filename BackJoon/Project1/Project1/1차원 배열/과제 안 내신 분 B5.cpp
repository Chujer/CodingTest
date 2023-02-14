#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> num;
	vector<int> num2;
	int c;
	c = 28;
	int index = 0;

	for (int i = 0; i < c; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	for (int i = 1; i < 31; i++)
	{
		if (find(num.begin(),num.end(),i) == num.end())
			num2.push_back(i);
	}


	for (int i : num2)
		cout << i << endl;

}