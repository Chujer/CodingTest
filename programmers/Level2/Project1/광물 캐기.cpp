#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] > b[0];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int pickCount = 0;
    for (int i = 0; i < picks.size(); i++)
    {
        pickCount += picks[i];
    }
    while (minerals.size() > pickCount * 5)
        minerals.pop_back();

    vector<vector<int>> mine(minerals.size() / 5 + 1, vector<int>(4, 0));

    for (int i = 0; i < mine.size(); i++)
    {
        for (int j = i*5; j < (i + 1) * 5 && j < minerals.size(); j++)
        {
            switch (minerals[j][0])
            {
                case 'd':
                    mine[i][0] += 25;
                    mine[i][1]++;
                    break;
                case 'i':
                    mine[i][0] += 5;
                    mine[i][2]++;
                    break;
                case 's':
                    mine[i][0] += 1;
                    mine[i][3]++;
                    break;
            default:
                break;
            }
        }
    }

    stable_sort(mine.begin(), mine.end(), cmp);

    int index = 0;

    for (int i = 0; i < mine.size(); i++)
    {
        while (index < 3 && picks[index] < 1)
            index++;

        if (index > 2)
            break;
        picks[index]--;

        switch (index)
        {
        case 0:
            answer += mine[i][1] * 1;
            answer += mine[i][2] * 1;
            answer += mine[i][3] * 1;
            break;
        case 1:
            answer += mine[i][1] * 5;
            answer += mine[i][2] * 1;
            answer += mine[i][3] * 1;
            break;
        case 2:
            answer += mine[i][1] * 25;
            answer += mine[i][2] * 5;
            answer += mine[i][3] * 1;
            break;
        default:
            break;
        }

    }

    return answer;
}

int main()
{
    solution({0,1,1 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}