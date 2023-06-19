#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int temp = N / 2;
	string nString;


	for(temp; temp<N;temp++)
	{
		int answer = temp;
		nString = to_string(temp);
		for (int i = 0; i< nString.size(); i++)
		{
			answer += nString[i] - 48 ;
		}
		if (answer == N)
		{
			cout << temp;
			return 0;
		}
	}
	cout << 0;

	return 0;
}