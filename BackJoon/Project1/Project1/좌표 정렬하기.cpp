#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

bool Compere(vector<int> a, vector<int> b)
{
	if (a[0] > b[0])
		return 0;
	else if (a[0] < b[0])
		return -1;
	else
	{
		if (a[1] > b[1])
			return 0;
		else if (a[1] < b[1])
			return -1;
	}
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> Ns;

	for (int i = 0; i < N; i++)
	{
		int tempX, tempY;
		cin >> tempX >> tempY;

		vector<int> temp = { tempX, tempY };
		Ns.push_back(temp);
	}

	
	sort(Ns.begin(), Ns.end(), Compere);


	for (vector<int> ns : Ns)
	{
		cout << ns[0] << " " << ns[1] << "\n";
	}
}