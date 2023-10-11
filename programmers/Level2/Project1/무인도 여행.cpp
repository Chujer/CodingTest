#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> check;
queue<pair<int, int>> que;

int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { 1,-1,0,0 };

void BFS(vector<string>map, int& score, int curX, int curY)
{
    score += map[curY][curX] - '0';
    for (int i = 0; i < 4; i++)
    {
        int x = curX + dirX[i];
        int y = curY + dirY[i];

        if (x >= map[0].size() || y >= map.size() || x < 0 || y < 0)
            continue;

        if (check[y][x] == -1)
            continue;

        if (map[y][x] == 'X')
        {
            check[y][x] = -1;
            continue;
        }

        check[y][x] = -1;
        que.push({ x, y });
    }

    while (!que.empty())
    {
        pair<int, int> temp = que.front();
        que.pop();
        BFS(map, score, temp.first, temp.second);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    check.resize(maps.size(), vector<int>(maps[0].size(), 0));

    for (int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'X')
                continue;

            if (check[i][j] == -1)
                continue;

            int temp = 0;
            if (check[i][j] != -1)
                check[i][j] = -1;

            BFS(maps, temp, j, i);

            if (temp != 0)
                answer.push_back(temp);
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.empty())
        answer.push_back(- 1);

    return answer;
}

int main()
{
    solution({ "X591X", "X1X5X", "X231X", "1XXX1" });
}