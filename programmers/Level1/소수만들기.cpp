#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int temp = 0;
    bool isPrime = true;
    map<int, int> datas;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size() ; j++)
        {
            for (int r = j + 1; r < nums.size(); r++)
            {
                isPrime = true;
                temp = nums[i] + nums[j] + nums[r];
                for (int x = 2; x < temp-1; x++)
                {
                    if (temp % x == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime)
                    answer++;
            }
        }
    }

    //answer = datas.size();

    return answer;
}
