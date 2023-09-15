#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> check;
queue<int> que;

void BFS(vector<vector<int>> computers, int curPC, int &answer, bool& next)
{

    for (int i = 0; i < computers.size(); i++)
    {
        if (check[curPC][i] == 0 && computers[curPC][i] == 1)
        {
            check[curPC][i] = answer;
            que.push(i);
            next = true;
        }
    }

    if (!que.empty())
    {
        int temp = que.front();
        que.pop();
        BFS(computers, temp, answer, next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 1;

    check.resize(computers.size(), vector<int>(computers[0].size(), 0));

    for (int i = 0; i < computers.size(); i++)
    {
        bool next = false;
        BFS(computers, i, answer, next);
        if (next == true)
            answer++;
    }

    return answer-1;
}

int main()
{
    solution(3, { {1,1,0}, {1,1,1}, {0,1,1} });
}