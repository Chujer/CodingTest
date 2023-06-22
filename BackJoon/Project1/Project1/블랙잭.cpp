#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> cards;
	int answer = 0;
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cards.push_back(temp);
	}
	sort(cards.begin(), cards.end(), greater<>());

	for (int i = 0; i < N - 2; i++)
	{
		int sum = 0;
		for (int j = i+1; j<N; j++)
		{
			for (int r = j+1; r < N; r++)
			{
				sum = 0;
				sum = cards[i] + cards[j] + cards[r];
				if (sum <= M)
				{
					if (sum > max)
						max = sum;
				}
			}
			
		}

	}
	cout << max;
}