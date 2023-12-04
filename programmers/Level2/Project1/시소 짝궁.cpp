#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, set<int>> arr;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, int> sub;
    
    for (int i = 0; i < weights.size(); i++)
    {
        int data[3] = { weights[i] * 2, weights[i] * 3, weights[i] * 4 };
        set<int> temp;

        for (int j = 0; j < 3; j++)
        {
            if (arr[data[j]].size() > 0)
            {
                temp.insert(arr[data[j]].begin(), arr[data[j]].end());
            }

            arr[data[j]].insert(weights[i]);
        }

        for (int t : temp)
        {
            answer += sub[t];
        }
        sub[weights[i]]++;
    }

    return answer;
}

int main()
{
    solution({ 100,100,100 });
}