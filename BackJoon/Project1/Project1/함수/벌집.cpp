#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int in;
	cin >> in;
	int answer = 1;

	int num = 1;
	int plusNum = 6;
	while (num < in)
	{
		num += plusNum;
		plusNum += 6;
		answer++;
	}

	cout << answer;
	

	return 0;
}