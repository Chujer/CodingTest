#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	float length, count;
	vector<int> score;

	cin >> length;

	for (int i = 0; i < length; i++)
	{
		cin >> count;
		float total = 0, avg,gm = 0;
		for (int j = 0; j < count; j++)
		{
			int temp;
			cin >> temp;
			total += temp;
			score.push_back(temp);
		}
		avg = total / (float)count;
		for (int j : score)
		{
			if (j > avg)
				gm++;
		}
		cout << fixed;
		cout.precision(3);
		//cout << 10.0f;
		float answer = ((float)gm / (float)count) * 100000.0f;
	/*	if ((int)answer % 10 > 5)
			answer += 1;*/
		answer = answer / 1000.0f;
		cout << answer << "%" << endl;
		score.clear();
	}
}