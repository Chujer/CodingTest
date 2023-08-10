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

	int N, M;
	cin >> N >> M;

	vector<int> datas(N + 1, 0);

	int maxNum;

	for (int i = 1; i < N+1; i++)
	{
		int temp;
		cin >> temp;
		if (i == 0)
			datas[0] = temp;
		else
			datas[i] = datas[i - 1] + temp;
	}

	for (int i = M; i < datas.size(); i++)
	{
		if (i == M)
			maxNum = datas[i] - datas[i - M];
		maxNum = max(datas[i] - datas[i - M], maxNum);
	}

	cout << maxNum;
}