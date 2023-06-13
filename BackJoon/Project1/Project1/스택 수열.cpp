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
	int count = 0;
	cin >> count;

	string str = "";
	int temp;
	
	vector<int> arr;
	vector<int> sta;
	int maxNum = 0;

	int index = 1;

	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		if (temp > maxNum)
			maxNum = temp;
		arr.push_back(temp);
	}

	//for (int i = 1; i <= maxNum; i++)
	//{
	//	sta.push_back(i);
	//}
	
	for (int a : arr)
	{

		while (true)
		{
			if (sta.size()>0 && sta.back() == a)
			{
				str += "-\n";
				sta.pop_back();
				break;
			}
			if (sta.size() == 0 || sta.back() < a)
			{
				str += "+\n";
				sta.push_back(index);
				index++;
			}
			else
			{
				str = "NO";
				cout << str;
				return 0;
			}
		}
	}

	cout << str;
}

