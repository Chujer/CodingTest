#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;
	
	vector<int> divisor;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
			divisor.push_back(i);
	}

	if (divisor.size() < K - 1)
		cout << 0;
	else
		cout << divisor[K - 1];

	return 0;
}