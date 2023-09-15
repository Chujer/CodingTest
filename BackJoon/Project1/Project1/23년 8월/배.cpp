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
vector<int> crain;
vector<int> box;

void moveCrain(int& answer)
{
	if (box.size() == 0)
		return;

	answer++;
	

	for (int i = 0; i < crain.size(); i++)
	{
		for (int j = box.size()-1; j >= 0; j--)
		{
			if (crain[i] >= box[j])
			{
				box.erase(box.begin() + j);
				break;
			}
			if (crain[i] < box.front())
				break;
		}
	}
	moveCrain(answer);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	crain.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> crain[i];
	}

	cin >> M;
	box.resize(M);
	for (int i = 0; i < M; i++)
	{
		cin >> box[i];
	}

	int answer = 0;

	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	if (box.back() > crain.back())
		answer = -1;
	else
	{
		moveCrain( answer);
	}
	cout << answer;
}