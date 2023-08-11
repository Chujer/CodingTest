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
	
	vector<long long> sum(1,0);
	long long N, M;
	long long answer = 0;
	cin >> N >> M;
	vector<long long> cnt(M);

	for (long long i = 1; i <= N; i++)
	{
		long long temp;
		cin >> temp;
		sum.push_back(temp + sum[i - 1]);
		cnt[sum[i] % M]++;
	}
	answer = cnt[0];
	for (long long i = 0; i < M; i++)
	{
		answer += (cnt[i] * (cnt[i] - 1) / 2);
	}
	cout << answer;
}