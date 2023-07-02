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
	long long  N;
	cin >> N;

	vector<long long> arr;
	map<long long, long long> mArr;

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf_s("%d",& temp);
		arr.push_back(temp);
		mArr[temp] ;
	
	}
	long long count = 0;
	for (pair<long long, long long> a : mArr)
	{
		mArr[a.first] = count;
		count++;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		printf("%d ", mArr[arr[i]]);
	}
}