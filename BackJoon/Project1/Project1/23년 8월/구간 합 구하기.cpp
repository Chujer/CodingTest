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

	vector<int> nums(100001, 0);

	int N, M;
	cin >> N >> M;

	

	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		nums[i] = nums[i - 1] + temp;
	}
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << nums[end] - nums[start-1] << "\n";
	}
}