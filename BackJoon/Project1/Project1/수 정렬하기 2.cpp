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
	set<int> nums;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nums.insert(temp);
	}

	for (int i : nums)
	{
		cout << i << "\n";
	}
}