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
	cin >> N;
	deque<int> arr;

	for (int i = 0; i < N; i++)
	{
		string commend;
		int temp;
		cin >> commend;
		if (commend == "push_front")
		{
			cin >> temp;
			arr.push_front(temp);
		}
		if (commend == "push_back")
		{
			cin >> temp;
			arr.push_back(temp);
		}
		if (commend == "pop_front")
		{
			if (arr.empty())
				cout << -1 << "\n";
			else
			{
				cout << arr.front() << "\n";
				arr.pop_front();
			}
		}
		if (commend == "pop_back")
		{
			if (arr.empty())
				cout << -1 << "\n";
			else
			{
				cout << arr.back() << "\n";
				arr.pop_back();
			}
		}
		if (commend == "size")
		{
			cout << arr.size() << "\n";
		}
		if (commend == "empty")
		{
			if (arr.empty())
				cout << 1 << "\n";
			else
			{
				cout << 0 << "\n";
			}
		}
		if (commend == "front")
		{
			if (arr.empty())
				cout << -1 << "\n";
			else
			{
				cout << arr.front() << "\n";
			}
		}
		if (commend == "back")
		{
			if (arr.empty())
				cout << -1 << "\n";
			else
			{
				cout << arr.back() << "\n";
			}
		}
	}
}