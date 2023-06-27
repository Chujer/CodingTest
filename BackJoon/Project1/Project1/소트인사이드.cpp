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
	string N;
	cin >> N;
	vector<char> num;

	for (char c : N)
	{
		num.push_back(c);
	}

	sort(num.begin(), num.end(), greater<>());

	for (char c : num)
	{
		cout << c;
	}
}