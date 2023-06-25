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
	vector<int> count;
	int avr=0;

	for (int i = 0 ; i < 5; i++)
	{
		int temp;
		cin >> temp;
		avr += temp;
		count.push_back(temp);
	}

	sort(count.begin(), count.end());

	cout << avr / 5 << endl << count[2];
}