#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

bool Check(long long n)
{
	if (n == 0 || n == 1)
		return false;

	if (n == 2)
		return true;

	for (long long i = 2; i <= sqrt(n)+1; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	long long N;
	cin >> N;

	vector<long long> num (N);
	

	for (long long i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for (long long n : num)
	{
		if (n == 0 || n == 1)
		{
			cout << 2 << "\n";
			continue;
		}

		for (n = n; true; n++)
		{
			if ( n == 1)
				continue;

			if (Check(n))
			{
				cout << n << "\n";
				break;
			}
		}
	}
}