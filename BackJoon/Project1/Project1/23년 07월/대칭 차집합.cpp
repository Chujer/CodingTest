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
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int ACount, BCount;
	int count = 0;
	
	map<int, int> A, B;
	cin >> ACount >> BCount;
	
	for (int i = 0; i < ACount; i++)
	{
		int temp;
		cin >> temp;
		A[temp]++;
	}
	for (int i = 0; i < BCount; i++)
	{
		int temp;
		cin >> temp;
		B[temp]++;
	}

	for (pair<int,int> a : A)
	{
		if (B.find(a.first) == B.end())
		{
			count++;
		}
	}
	for (pair<int, int> b : B)
	{
		if (A.find(b.first) == A.end())
		{
			count++;
		}
	}
	cout << count;
}