#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<char> pm;
	vector<int> nums;

	string data;
	int count = 0;
	int tempCount = 0;
	cin >> data;

	for (int i = data.size();  i >= 0 ; i--)
	{
		if (data[i] == '+' || data[i] == '-')
		{
			int num = stoi(data.substr(i+1, data.size()));

			if (data[i] == '+')
				tempCount += num;
			else if (data[i] == '-')
			{
				count += (tempCount + num) * -1;
				tempCount = 0;
			}
			data = data.substr(0, i);
		}
	}
	count += stoi(data) + tempCount;
	cout << count;
}