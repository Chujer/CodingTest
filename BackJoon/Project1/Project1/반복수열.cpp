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
	int D, A;
	cin >> D >> A;
	map<int, int> datas;
	int answer = 0;

	datas[D]++;


	while (true)
	{
		D = pow(D % 10, A) + pow((D % 100) / 10, A) + pow((D % 1000) / 100, A) + pow((D % 10000) / 1000, A) + pow((D % 100000) / 10000, A);

		if (datas[D] == 3)
			break;
		datas[D]++;
	}

	for (pair<int, int> d : datas)
	{
		if (d.second == 1)
			answer++;
	}
	cout << answer;
}