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


	for (int i = 0; i < N; i++)
	{
		stack<char> arr;
		string temp;
		cin >> temp;
		for (char c : temp)
		{
			if (c == '(')
				arr.push('(');
			else
			{
				if (arr.empty())
				{
					arr.push(')');
					break;
				}
				arr.pop();

			}
		}
		if (arr.size() == 0)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}