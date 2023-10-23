#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int DP[1000001];
int DP2[1000001];

bool cmd(vector<int> a, vector<int> b)
{
    if (a[1] - a[0] == b[1] - b[0])
    {
        return a[0] <  b[0];
    }
    return a[1] - a[0] < b[1] - b[0];
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<vector<int>> answerData;

    deque<int> data;

    DP[0] = 0;
    DP[1] = sequence[sequence.size() - 1];
    DP2[0] = 0;
    DP2[1] = sequence.size()-1;
    if (DP[1] == k)
    {
        answerData.push_back({ (int)sequence.size() - 1, (int)(sequence.size()) - 1 });
    }

    for (int i = 2; i < sequence.size()+1; i++)
    {
        DP[i] = sequence[sequence.size() - i] + DP[i - 1];
        if (DP[i] > k)
        {
            DP2[i] = DP2[i - 1] - 1;
            DP[i] = sequence[sequence.size() - i] + DP[i - 1] - sequence[DP2[i-1]];
        }
        else
        {
            DP2[i] = DP2[i - 1];
        }
        
        if (DP[i] == k)
        {
            answerData.push_back({ (int)sequence.size() - i,  DP2[i] });
        }
    }
    
    stable_sort(answerData.begin(), answerData.end(), cmd);

    answer = answerData.front();

    return answer;
}

int main()
{
    solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);
}