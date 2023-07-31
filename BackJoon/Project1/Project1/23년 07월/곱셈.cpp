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

long long CustomPow(long long A, long long B, long long C)
{
	if (B == 1)
		return A % C;

	long long answer = CustomPow(A, B / 2, C);

	if (B % 2 == 0)
	{
		return answer * answer % C;
	}
	else
		return (answer * answer % C) * A% C;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);


	long long A, B, C;
	cin >> A >> B >> C;

	long long sum = A;
	long long count = 1;

	cout << CustomPow(A, B, C);
}