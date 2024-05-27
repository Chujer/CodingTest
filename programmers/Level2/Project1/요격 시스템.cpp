#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0])
        return a[1] > b[1];
    return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 1;

    sort(targets.begin(), targets.end(), cmp);


    double lastEndPos = targets[0][1] - 0.1f;
    for (int i = 1; i < targets.size(); i++)
    {
        if (targets[i][0] == targets[i][1])
            answer++;
        double temp = ((double)targets[i][0]) + 0.5f;
        if (targets[i][0] <= temp && lastEndPos >= temp)
        {
            lastEndPos = min(lastEndPos, (double)targets[i][1]-0.1f);
            continue;
        }
        else
        {
            answer++;
            lastEndPos = targets[i][1] - 0.1f;
        }

    }

    return answer;
}

int main()
{
    //solution({{4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}} );
    //solution({ {4, 5}, {5,6}, {4,8} });
    //solution({ {4, 5}, {4,5}, {4,5} });
    solution({ {0,1}, {0,0} });
}