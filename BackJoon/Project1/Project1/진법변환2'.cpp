#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int num;
	int binary;
	
	string answer = "";
	int digits = 1;

	cin >> num;
	cin >> binary;

	while (num != 0)
	{
		int temp;
		temp = num % binary;
		if (temp > 9)
			answer += (char)((temp-10) + 'A');
		else
			answer += to_string(temp);
		num = num / binary;
	}
	reverse(answer.begin(), answer.end());

	cout << answer;

	return 0;
}