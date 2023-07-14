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

long long Gcd(long long a, long long b)
{
	if (b == 0)
		return a;

	return Gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N ;
	cin >> N;
	vector<long long> trees(N);
	vector<long long> intervals(N-1);
	cin >> trees[0];
	for (int i = 1; i < N; i++)
	{
		cin >> trees[i];
		intervals[i-1] = trees[i] - trees[i - 1];
		
	}
	long long gcd;
	gcd = Gcd(intervals[0], intervals[1]);
	for (int i = 2; i < intervals.size(); i++)
	{
		gcd = Gcd(gcd, intervals[2]);
	}

	int count = (trees[N-1] - trees[0]) / gcd;
	count -= intervals.size();


	cout << count;
}