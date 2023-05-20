#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int in[2];
	cin >> in[0];
	cin >> in[1];

	vector<vector<int>> A,B;

	for (int i = 0; i < in[0]; i++)
	{
		vector<int> tempA;
		for (int j = 0; j < in[1]; j++)
		{
			int temp = 0;
			cin >> temp;
			tempA.push_back(temp);
		}
		A.push_back(tempA);
	}
	for (int i = 0; i < in[0]; i++)
	{
		vector<int> tempB;
		for (int j = 0; j < in[1]; j++)
		{
			int temp = 0;
			cin >> temp;
			tempB.push_back(temp);
		}
		B.push_back(tempB);
	}

	for (int i = 0; i < in[0]; i++)
	{
		vector<int> tempAnswer;
		for (int j = 0; j < in[1]; j++)
		{
			int temp = 0;
			temp = A[i][j] + B[i][j];
			cout << temp << " ";
		}
		cout << endl;
	}

	return 0;
}