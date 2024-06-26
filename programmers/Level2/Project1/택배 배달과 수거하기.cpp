#include <string>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    unordered_map<int, int> deliver;
    unordered_map<int, int> pickup;
    int del = 0;
    int pick = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] > 0)
            deliver[i] = deliveries[i];
        del += deliveries[i];
        if (pickups[i] > 0)
            pickup[i] = pickups[i];
        pick += pickups[i];
    }

    while (del > 0 || pick > 0)
    {
        int count = del > cap ? cap : del;
        int count2 = cap;
        unordered_map<int, int>::iterator iter = deliver.begin();
        unordered_map<int, int>::iterator iter2 = pickup.begin();

        answer += (max((*iter).first, (*iter2).first) + 1) * 2;

        while (count > 0 && del > 0)
        {
            if ((*iter).second > count)
            {
                (*iter).second -= count;
                del -= count;
                count = 0;
            }
            else
            {
                del -= (*iter).second;
                count -= (*iter).second;
                deliver.erase(iter);    
                iter = deliver.begin();
            }
        }
        while (count2 > 0 && pick > 0)
        {
            if ((*iter2).second > count2)
            {
                (*iter2).second -= count2;
                pick -= count2;
                count2 = 0;
            }
            else
            {
                pick -= (*iter2).second;
                count2 -= (*iter2).second;
                pickup.erase(iter2);
                iter2 = pickup.begin();
            }
        }
    }

    return answer;
}

int main()
{
    solution(2, 7, { 1, 0, 2, 0, 1, 0, 2 }, { 0, 2, 0, 1, 0, 2, 0 });
}