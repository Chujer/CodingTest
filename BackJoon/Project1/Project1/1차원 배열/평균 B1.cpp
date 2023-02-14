#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<float> num;
	vector<int> num2;
	float c;
	float total =0;
	cin >> c;

	float max = 0;
	for (float i = 0; i < c; i++)
	{
		float temp;
		cin >> temp;
		num.push_back(temp);
		if (temp > max)
			max = temp;
	}

	for (float i = 0; i < num.size(); i++)
	{
		total += num[i] / max * 100;
	}

	cout << total/c;
}