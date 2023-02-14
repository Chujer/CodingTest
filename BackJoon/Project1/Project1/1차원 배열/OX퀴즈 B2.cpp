#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	int a;
	cin >> a;
	int count = 0;
	int score = 0;

	for(int i =0; i<a;i++)
	{
		cin >> s;
		for (char c : s)
		{
			if (c == 'O')
			{
				score += 1 + count;
				count++;
			}
			else
				count = 0;
		}

		cout << score<< endl;
		score = 0;
		count = 0;
	}
	
}