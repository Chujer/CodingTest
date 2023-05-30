#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int A, B, V;
	cin >> A;
	cin >> B;
	cin >> V;

	int cur = 0;
	int answer = 0;

	if (A == V)
	{
		cout << 1;
		return 0;
	}

	V -= A;
	A -= B;
	if (V / A == 0)
		answer = 2;
	else
	{
		if (V % A == 0)
			answer = V / A+  1;
		else
			answer = V / A + 2;
	}

	//while (cur < V)
	//{
	//	cur += A;
	//	if (cur < V)
	//		cur -= B;
	//	answer++;
	//}
	cout << answer;

	return 0;
}