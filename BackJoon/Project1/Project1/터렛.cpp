#include <iostream>
#include <vector>

#include <math.h>

using namespace std;

int main()
{
	int cases;
	int x1, y1, x2, y2, r1, r2;

	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double distanceX = pow((x2 - x1), 2);
		double distanceY = pow((y2 - y1), 2);

		double distance = sqrt(distanceX + distanceY);



		if (x1 == x2 && y1 == y2)
		{

			if (r2 == 0 && r1 == 0)
			{
				cout << 1 << endl;
				continue;
			}
			if (r1 == r2)
			{
				cout << -1 << endl;
				continue;
			}
			else
			{
				cout << 0 << endl;
				continue;
			}
		}

		if (distance > r1 + r2 || distance < abs(r1 - r2))
		{
			cout << 0 << endl;
			continue;
		}
		else if (distance < r1 + r2 && distance > abs(r2 - r1))
		{
			cout << 2 << endl;
			continue;
		}
		else if (distance == r1 + r2 || distance == abs(r2-r1))
		{
			cout << 1 << endl;
			continue;
		}
	}
}