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

	else
		return Gcd(b, a % b);
}

long long Lcm(long long a, long long b)
{
	long long d = Gcd(a, b);
	return (a * b) / Gcd(a,b);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N1, N2, M1, M2;

	cin >> N1 >> N2 >> M1 >> M2;

	long long lcm = Lcm( N2 , M2);

	long long answer1, answer2;
	answer1 = (lcm/N2  * N1) + (lcm/M2 * M1);
	answer2 = lcm;

	lcm = Gcd(answer1, answer2);

	answer1 /= lcm;
	answer2 /= lcm;
		
	cout << answer1 << " " << answer2;

}