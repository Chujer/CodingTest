#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
	int N;
	map<int, int> count;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d",&temp);
		count[temp]++;
	}

	for (pair<int,int> num : count)
	{
		for (int i = 0; i < num.second; i++)
		{
			printf("%d", num.first);
			printf("\n");
		}

	}
}