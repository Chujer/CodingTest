#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> bestScore;
    int maxPeople = k;

    for (int s : score)
    {
        if (bestScore.size() < k)
        {
            bestScore.push_back(s);
            sort(bestScore.begin(), bestScore.end());
            answer.push_back(bestScore.front());
            continue;
        }
        for(int i = k-1; i>-1;i--)
        {
            if (s > bestScore[i])
            {
                bestScore.push_back(s);
                sort(bestScore.begin(), bestScore.end());
                bestScore.erase(bestScore.begin());
                answer.push_back(bestScore.front());
                break;
            }
            if (i == 0)
                answer.push_back(bestScore.front());
        }
    }

    return answer;
}

int main()
{
    solution(3, { 10, 100, 20, 150, 1, 100, 200 });
}