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

	stack<int> commend;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int tempInt;
			cin >> tempInt;
			commend.push(tempInt);
		}
		if (temp == "top")
		{
			if (commend.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			cout << commend.top() << "\n";
		}
		if (temp == "size")
		{
			cout << commend.size() << "\n";
		}
		if (temp == "empty")
		{
			cout << commend.empty() << "\n";
		}
		if (temp == "pop")
		{
			if (commend.empty())
			{
				cout << -1 << "\n";
				continue;
			}
			if (commend.empty())
				cout << -1 << "\n";
			else
				cout << commend.top() << "\n";
			commend.pop();
		}
	}
}