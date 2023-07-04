#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N, M;
	cin >> N;
	map<int, int> card;
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		card[temp]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (card[temp] > 0)
		{
			cout << card[temp] << " ";
		}
		else
			cout << 0 << " ";
	}
}