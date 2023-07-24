#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second > b.second)
	{
		return true;
	}
	else if (a.second == b.second)
	{
		if (a.first < b.first)
			return true;
	}
	return false;
}

void Sort(const map<int, int>& m)
{
	vector<pair<int, int>> a;

	for (auto& mArr : m)
	{
		a.push_back(mArr);
	}

	sort(a.begin(), a.end(), cmp);

	if (a.size() > 1 && a[0].second == a[1].second)
		cout << a[1].first << "\n";
	else
		cout << a[0].first << "\n";
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	map<int, int> mArr;
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		mArr[arr[i]]++;
		sum += arr[i];
	}

	sort(arr.begin(), arr.end(), greater<>());
	sum /= arr.size();
	int realSum = sum * 10;


	if (abs(realSum % 10) > 4)
	{
		if (realSum > 0)
			realSum = realSum / 10 + 1;
		else
			realSum = realSum / 10 - 1;
	}
	else
		realSum = realSum / 10;

	cout << realSum <<"\n";
	cout << arr[arr.size() / 2] << "\n";
	Sort(mArr);
	cout << arr.front() - arr.back() << "\n";
}