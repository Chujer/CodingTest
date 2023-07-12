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

	int N, C;
	cin >> N >> C;
	
	vector<int> arr(N);
	int left = 1;
	int right;
	int distance;
	int count = 0;

	cin >> arr[0];
	for (int i = 1; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	right = (arr.back() - arr.front());

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int first = arr.front();
		count = 1;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] - first >= mid)
			{
				first = arr[i];
				count++;
			}
		}

		if (count >= C)
		{
			left = mid + 1;
			distance = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << distance;
}