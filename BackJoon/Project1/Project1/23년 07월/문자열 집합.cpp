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
	map<string, bool> arr;
	int count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		arr.insert(make_pair(temp, true));
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (arr[temp] == true)
			count++;
	}
	cout << count;
}