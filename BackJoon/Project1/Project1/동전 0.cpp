#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int count, money;
	cin >> count >> money;

	vector<int> arr;
	int answer = 0;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}


	for (int i = count - 1; i >= 0; i--)
	{
		if (money < arr[i])
			continue;

		answer += money / arr[i];
		money = money % arr[i];
	}
	cout << answer;
}