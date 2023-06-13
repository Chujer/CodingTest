#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{

	while (true)
	{
		int a = 0, b = 0, c = 0;

		cin >> a >> b >> c;
		
		if (a+b+c == 0)
			break;
		
		if (a > b && a > c)
		{
			if (b + c <= a)
			{
				cout << "Invalid" << endl;
				continue;
			}
		}
		if (b > a && b > c)
		{
			if (a + c <= b)
			{
				cout << "Invalid" << endl;
				continue;
			}
		}
		if (c > a && c > b)
		{
			if (a + b <= c)
			{
				cout << "Invalid" << endl;
				continue;
			}
		}

		if (a == b && b == c)
		{
			cout << "Equilateral" << endl;
			continue;
		}
		else if (a == b || b == c || a == c)
		{
			cout << "Isosceles" << endl;
			continue;
		}

		

		cout << "Scalene" << endl;

	}
	return 0;
}