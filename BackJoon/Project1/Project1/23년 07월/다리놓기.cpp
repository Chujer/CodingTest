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

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N, M;
		int count = 1;
		cin >> N >> M;
		
		for (int i = 0; i < N; i++)
		{
			count *= M - i;
			count /= 1 + i;
		}
		cout << count << endl;
	}
}