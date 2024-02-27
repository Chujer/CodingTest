#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, less<>> stages;

    int temp = n;
    for (int i = 0; i < enemy.size(); i++)
    {
        temp -= enemy[i];
        stages.push(enemy[i]);
        if (temp < 0)
        {
            if (k > 0)
            {
                k--;
                temp += stages.top();
                stages.pop();

            }
            else
                break;
        }
        answer++;
    }

    return answer;
}

int main()
{
    solution(2, 4, {3,3,3,3 });
}