#include <string>
#include <vector>
#include <stack>

using namespace std;

void Check(int k, vector<vector<int>> dungeons, int index, int answer, int& maxAnswer)
{
    if (k >= dungeons[index][0])
    {
        k -= dungeons[index][1];
        answer++;
    }
    else
    {
        if (maxAnswer < answer)
            maxAnswer = answer;
        return;
    }

    dungeons.erase(dungeons.begin()+index);

    if (dungeons.empty())
    {
        if (maxAnswer < answer)
            maxAnswer = answer;
        return;
    }

    for (int i = 0; i < dungeons.size(); i++)
    {
        Check(k, dungeons, i, answer, maxAnswer);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int maxAnswer = 0;

    for(int i =0; i< dungeons.size(); i++)
        Check(k, dungeons, i, answer, maxAnswer);

    
    return maxAnswer;
}


void main()
{
    int a =solution(80, { {80,20}, {50,40}, {30,10} });
    return;
}