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

	set<string> str;

	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++)
	{
		string temp = "";
		temp += S[i];
		str.insert(temp);
		for (int j = 0; j < S.size(); j++)
		{
			string temp2 = S.substr(i, j);
			str.insert(temp2);
		}
	}
	cout << str.size();
}