#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	vector<int> answer;
	int sum = 0;

	while (true)
	{
		sum = 0;
		answer.clear();
		cin >> n;
		
		if (n == -1)
			break;

		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				answer.push_back(i);
				sum += i;
				if (sum > n)
				{
					break;
				}
			}
		}
		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < answer.size(); i++)
			{
				if (i == answer.size() - 1)
					cout << answer[i];
				else
					cout << answer[i] << " + ";
			}
		}
		else
			cout << n << " is NOT perfect.";
		cout << endl;
	}
}