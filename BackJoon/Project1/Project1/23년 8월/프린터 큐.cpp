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
		deque<int> printer;
		priority_queue<int, vector<int>, less<>> arr;
		int count, targetIndex;
		int target = 0;
		int answer = 0;

		cin >> count >> targetIndex;

		for (int j = 0; j < count; j++)
		{
			int temp;
			cin >> temp;
			arr.push(temp);

			printer.push_back(temp);
			if (targetIndex == j)
				target = temp;
		}
		int size = printer.size();
		
		while (printer.size() != 0)
		{
			if (printer.front() != arr.top())
			{
				int temp = printer.front();
				printer.pop_front();
				printer.push_back(temp);

				if (targetIndex == 0)
					targetIndex = printer.size()-1;
				else
					targetIndex--;
			}
			else
			{
				answer++;
				if (targetIndex == 0)
					cout << answer << "\n";
				printer.pop_front();
				arr.pop();
				targetIndex--;
			}
		}
	}
	
}