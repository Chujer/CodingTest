#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	int arr[3];
	int check = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		check += arr[i];
	}

	if (check != 180)
		cout << "Error";
	else
	{
		if (arr[0] == arr[1] && arr[1] == arr[2])
			cout << "Equilateral";
		else if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	

}
