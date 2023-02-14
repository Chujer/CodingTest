#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> num;
	vector<int> num2;
	int c;
	c = 10;
	int index = 0;

	for (int i = 0; i < c; i++)
	{
		int temp;
		cin >> temp;
		if(find(num.begin(),num.end(),temp%42)==num.end())
			num.push_back(temp %42);
	}
	cout << num.size();
}