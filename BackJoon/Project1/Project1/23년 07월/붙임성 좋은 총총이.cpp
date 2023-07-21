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

	int N;
	int count = 1;
	map<string, string> chong;

	cin >> N;
	chong["ChongChong"] = "ChongChong";

	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (chong[s1]== "" || chong[s2] == "")
		{
			if (chong[s1] == "ChongChong" || chong[s2] == "ChongChong")
			{
				chong[s1] = "ChongChong";
				chong[s2] = "ChongChong";

				count++;
			}
		}
	}
	cout << count;
}