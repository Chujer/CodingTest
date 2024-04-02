#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<pair<long long, double>> DP;
    DP.push_back({ k ,0});

    while (DP.back().first > 1)
    {
        int y;
        if (DP.back().first % 2 == 0)
            y = DP.back().first / 2;
        else
            y = DP.back().first * 3 + 1;

        double gg = (double)(DP.back().first + y) / 2;

        DP.push_back({ y, DP.back().second + gg });
    }

    int size = DP.size();
    for (int i = 0; i < ranges.size(); i++)
    {
        int pos = (size - 1) + ranges[i][1];

        if (ranges[i][0] == 0 && ranges[i][1] == 0)
        {
            answer.push_back(DP[size - 1].second);
            continue;
        }
                  
        if (ranges[i][0] > pos)
            answer.push_back(-1.0f);
        else
            answer.push_back(DP[pos].second - DP[ranges[i][0]].second);
    }
    
    return answer;
}

int main()
{
    solution(5, { {8,0} });
}