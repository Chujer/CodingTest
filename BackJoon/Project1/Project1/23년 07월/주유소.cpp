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

	long long N;
	long long sum = 0;
	
	cin >> N;

	long long pos = 0;
	
	vector<long long> city(N);
	vector<long long> distance(N-1);

	for (long long i = 0; i < N - 1; i++)
	{
		cin >> distance[i];
	}


	for (long long i = 0; i < N; i++)
		cin >> city[i];
	

	for (;pos != N-1;)
	{
		long long dis = 0;
		long long nextPos = pos;
		long long curPos = pos;

		for (long long i = pos+1; i < N-1; i++)
		{
			if (city[curPos] >= city[i])
			{
				nextPos = i;
				break;
			}
		}
		if (curPos == nextPos)
			nextPos = N - 1;

		for (long long i = pos; i < nextPos; i++)
		{
			dis += distance[i];
		}
		sum += city[curPos] * dis;
		pos = nextPos;
		curPos = pos;
	}

	cout << sum;
}
