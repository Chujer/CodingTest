#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;
	string s;
	int a;

	cin >> a;
	vector<int> count1;
	vector<int> count2;

	for (int i = 0; i < a; i++)
	{
		int b, c;
		cin >> b;
		cin >> c;
		count1.push_back(b);
		count2.push_back(c);
	}

	for (int i = 0; i < a; i++)
	{
		cout << "Case #" << i + 1 << ": " << count1[i] << " + " << count2[i] << " = " << count1[i] + count2[i] << endl;
	}

	return 0;
}