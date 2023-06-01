#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<int> A, B;

	while (true)
	{
		int tempA, tempB;
		cin >> tempA;
		cin >> tempB;
		if (tempA == 0, tempB == 0)
			break;

		A.push_back(tempA);
		B.push_back(tempB);
	}

	for (int i = 0; i < A.size(); i++)
	{
		if (B[i] % A[i] == 0)
			cout << "factor" << endl;
		else if (A[i] % B[i] == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;

	}

	return 0;
}