#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int a = 1;
	vector<int> answer;
	for (int b = 1; b<10000;b++)
	{
		string ac =  to_string(a);

		int num = 0;
		while (a < 10000)
		{
			num = a;
			for (char c : ac)
			{
				num += (int)(c) - '0';
				if (find(answer.begin(), answer.end(), num) == answer.end())
					answer.push_back(num);
			}
			a = num;
		}
	}
	for (int i : answer)
		cout << i << endl;
}