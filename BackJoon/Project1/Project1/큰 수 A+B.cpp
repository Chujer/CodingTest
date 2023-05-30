#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string A, B;
	string answer = "";

	cin >> A;
	cin >> B;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int nextNum = 0;
	int mexCount = A.length() > B.length() ? A.length() : B.length();

	for (int i = 0; i < mexCount; i++)
	{
		int tempSum = 0;
		tempSum += nextNum;
		nextNum = 0;
		if (i < A.length())
		{
			tempSum += A[i] - '0';
		}
		if (i < B.length())
		{
			tempSum += B[i] - '0';
		}

		if (tempSum > 9)
		{
			nextNum = tempSum / 10;
			answer += to_string(tempSum % 10);
		}
		else
		{
			nextNum = tempSum / 10;
			answer += to_string(tempSum);
		}
	}
	if (nextNum != 0)
		answer += to_string(nextNum);

	reverse(answer.begin(), answer.end());

	cout << answer;

	return 0;
}