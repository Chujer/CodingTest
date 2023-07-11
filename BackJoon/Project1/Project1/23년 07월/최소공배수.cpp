#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

// �ִ�����
long long gcd(long long a, long long b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

// �ּҰ����
long long lcm(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M;
	cin >> N >> M;
	cout << lcm(N, M);
}