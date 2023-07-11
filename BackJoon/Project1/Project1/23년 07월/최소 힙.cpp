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

	priority_queue<int, vector<int>, greater <int>> arr;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (arr.size() == 0)
			{
				cout << 0 << "\n";
				continue;
			}
			else
			{
				cout << arr.top() << "\n";
				arr.pop();
				continue;
			}
		}
		arr.push(temp);
	}
	
	
}