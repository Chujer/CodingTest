#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	int count;
	
	int stairs[300];
	int play[300];

	cin >> count;

	for (int i = 0; i < count; i++)
		cin >> stairs[i] ;

	play[0] = stairs[0];
	play[1] = play[0] + stairs[1];
	play[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < count; i++)
	{
		play[i] = max(play[i-3] + stairs[i-1] + stairs[i], play[i - 2] + stairs[i]);
	}

	cout << play[count - 1];
}