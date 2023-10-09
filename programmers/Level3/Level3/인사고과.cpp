#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmd(vector<int> a, vector<int>b)
{
    return a[0] + a[1] > b[0] + b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;

    pair<int, int> one = {scores[0][0], scores[0][1]};

    sort(scores.begin(), scores.end(), cmd);

    vector<int> leavings;

    
    if (scores.size() == 1)
        return 1;

    for (int i = scores.size() -1 ; i >= 0; i--)
    {
        if (one.first < scores[i][0] && one.second < scores[i][1])
            return -1;

        if (scores[i][0] + scores[i][1] > one.first + one.second)
        {
            leavings.push_back(i);
        }
    }
    answer = leavings.size() + 1;

    for (int i  : leavings)
    {
        for (int j = 0; j < scores.size(); j++)
        {
            if (i == j)
                continue;
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
            {
                answer--;
                break;
            }

            if (scores[j][0] + scores[j][1] <= scores[i][0] + scores[i][1])
            {
                break;
            }
        }
    }


    return answer;
}

int main()
{
    solution({ {4,2} , {6,2}, {2,6} });
}