#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    vector<int> DP1(sticker.size());
    vector<int> DP2(sticker.size());

    if (sticker.size() == 1)
        return sticker[0];

    DP1[0] = sticker[0];
    DP1[1] = max(DP1[0], sticker[1]);
    DP2[1] = sticker[1];

    for (int i = 2; i < sticker.size()-1; i++)
    {
        DP1[i] = max(DP1[i - 1], DP1[i - 2] + sticker[i]);
    }

    for (int i = 2; i < sticker.size(); i++)
    {
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + sticker[i]);
    }

    DP1.pop_back();

    answer = max(DP1.back(), DP2.back());

    return answer;
}

int main()
{
    solution({ 14, 6, 5, 11, 3, 9, 2, 10 });
}