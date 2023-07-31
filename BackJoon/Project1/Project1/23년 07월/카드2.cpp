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

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> cards;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cards.push_back(i);
	}

	while (cards.size() != 1)
	{
		int temp;
		cards.pop_front();
		temp = cards.front();
		cards.pop_front();
		cards.push_back(temp);
	}

	cout << cards.front();
}