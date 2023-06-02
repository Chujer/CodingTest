#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string temp;
	vector<string> str;
	string answer = "";
	int maxSize = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		str.push_back(temp);
		if (maxSize < temp.size())
			maxSize = temp.size();
	}

	for (int i = 0; i < str.front().size(); i++)
	{
		for (int j = 0; j < str.size(); j++)
		{
			if (i >= str[j].size())
				continue;
			answer += str[j][i];
		}
	}

	cout << answer;

}