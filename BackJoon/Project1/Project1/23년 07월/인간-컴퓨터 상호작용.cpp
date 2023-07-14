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

	string S;
	cin >> S;

	vector<map<char, int>> arr(S.size());
	long long N, l, r;
	char a;
	cin >> N;
	
	map<char, int> c; 
	c.insert(make_pair(S[0], 1));
	arr[0] = c;

	for (int i = 1; i< S.size() ; i++)
	{
		map<char, int> temp;
		int count = 0;

		temp[S[i]]++;
		arr[i] = arr[i - 1];
		arr[i][S[i]] ++;
	}


	for (int i = 0; i < N; i++)
	{
		cin >> a >> l >> r;
		int count = 0;

		if (l == 0)
			count = arr[r][a];
		else
			count = arr[r][a] - arr[l-1][a];


		cout << count << "\n";
	}
}