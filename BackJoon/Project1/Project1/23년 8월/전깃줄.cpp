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
	vector<pair<int, int>> v(N+1);

	int DP[101] = {0};
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;

		v[i] = { start, end };
	}

	sort(v.begin(), v.end());


	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)	//안겹치고 최대한 넣을수 있는 상황들을 추가
			{
				if (DP[i] <= DP[j])			//안겹치고 최대한 넣을수 있는 상황들을 추가
					DP[i] = DP[j] + 1;
           	}

		}

		answer = max(answer, DP[i]);
	}

	cout << N - answer;

}