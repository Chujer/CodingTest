#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int x = 0, y = 0, w = 0, h = 0;
	int width, height;
	int answer;

	cin >> x >> y >> w >> h;

	width = w / 2 < x ? w - x : x;
	height = h / 2 < y ? h - y : y;

	answer = width <  height ? width : height;

	cout << answer;
}