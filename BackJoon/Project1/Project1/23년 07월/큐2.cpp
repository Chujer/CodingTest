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
	queue<int> que;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			que.push(num);
		}

		if (str == "pop")
		{
			if (que.empty())
				cout << -1 << "\n";
			else
			{
				cout << que.front() << "\n";
				que.pop();
			}
		}
		
		if (str == "size")
			cout << que.size() << "\n";

		if (str == "empty")
		{
			if (que.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}

		if (str == "front")
		{
			if (que.empty())
				cout << -1 << "\n";
			else
				cout << que.front() << "\n";
		}

		if (str == "back")
		{
			if (que.empty())
				cout << -1 << "\n";
			else
				cout << que.back() << "\n";
		}
	}
}