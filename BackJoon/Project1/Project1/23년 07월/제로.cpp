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

	int N;
	stack<int> num;

	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (!num.empty())
			{
				num.pop();
				continue;
			}
		}
		num.push(temp);
	}

	for (;!num.empty();)
	{
		sum += num.top();
		num.pop();
	}
	cout << sum;
}