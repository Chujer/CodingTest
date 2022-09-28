#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    int tempIndex = 0;

    while (budget >= d[tempIndex])
    {
        budget -= d[tempIndex];
        tempIndex++;
        answer++;
        if (tempIndex == d.size())
            break;
    }


    return answer;
}
