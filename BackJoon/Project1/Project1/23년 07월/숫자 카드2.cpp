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
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<int, int> cards;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cards[temp]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout << cards[temp] << " ";
	}
}