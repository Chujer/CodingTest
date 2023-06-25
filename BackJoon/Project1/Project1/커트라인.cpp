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
	int N, K;
	vector<int> score;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		score.push_back(temp);
	}

	sort(score.begin(), score.end(),greater<>());

	cout << score[K-1];
}