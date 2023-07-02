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
	int N;
	cin >> N;
	
	vector<vector<string>> arr(201);

	for (int i = 0; i < N; i++)
	{
		int temp1;
		string temp2;
		cin >> temp1 >> temp2;
		arr[temp1].push_back(temp2);
	}

	for (int i = 0; i< arr.size(); i++)
	{
		if (arr[i].size() == 0)
			continue;
		for(string a : arr[i])
			cout << i << " " << a << "\n";
	}

	return 0;
}