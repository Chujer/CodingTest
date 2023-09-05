#include<vector>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> que;
vector<vector<int>> mapss;
vector<vector<int>> check;

void BFS(pair<int, int> curPos, int& answer)
{
    if (curPos.first == mapss[0].size()-1 && curPos.second == mapss.size()-1)
    {
        answer = check[mapss.size()-1][mapss[0].size()-1];
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int x = dirX[i] + curPos.first;
        int y = dirY[i] + curPos.second;

        if (x < 0 || y < 0 || x > check[0].size()-1 || y > check.size()-1)
            continue;

        if (mapss[y][x] == 0)
            continue;

        if (check[y][x] != 0)
            continue;

        check[y][x] = check[curPos.second][curPos.first] + 1;
        que.push({x,y});
    }

    while (!que.empty())
    {
        if (curPos.first == mapss[0].size() - 1 && curPos.second == mapss.size() - 1)
        {
            return;
        }
        pair<int, int> temp;
        temp = que.front();
        que.pop();

        BFS(temp, answer);
    }
}

int solution(vector<vector<int> > maps)
{
    if (maps[0][0] == 0)
        return -1;
    int answer = -1;
    mapss = maps;
    check.resize(maps.size(), vector<int>(maps[0].size(), 0));
    check[0][0] = 1;

    BFS({ 0,0 }, answer);

    return answer;
}

int main()
{

    cout << solution({ {1, 0, 1, 1, 0},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1},{0, 0, 1, 1, 1} });

    return 0;
}