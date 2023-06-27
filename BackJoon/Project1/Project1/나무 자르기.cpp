#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N, M;
	vector<long long> sizes;
	long long answer = 0;
	long long total = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		total += temp;
		sizes.push_back(temp);
	}

	if (total < M)
	{
		cout << 0;
		return 0;
	}

	if (N == 1)
	{
		cout <<  sizes.front() - M;
		return 0;
	}	

	sort(sizes.begin(), sizes.end(), greater<>());

	long long curSize = sizes.front();
	long long lastIndex = 0;
	long long plusSize = 1;
	while (true)
	{
		if (answer >= M)
			break;

		if (lastIndex != sizes.size()-1 && sizes[lastIndex + 1] >= curSize)
		{
			while (sizes[lastIndex + 1] >= curSize)
			{
				lastIndex++;
				plusSize++;
			}
		}

		answer += plusSize;
		curSize--;
	}
	cout << curSize;
}
