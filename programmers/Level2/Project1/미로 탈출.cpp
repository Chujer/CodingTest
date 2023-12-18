#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> check;
queue<pair<int, int>> que;

int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };

void BFS(vector<string>& maps,pair<int,int> curPos,  pair<int,int> endPos)
{
    int curX = curPos.first;
    int curY = curPos.second;

    for (int i = 0; i < 4; i++)
    {
        int x = curX + dirX[i];
        int y = curY + dirY[i];

        if (y < 0 || x < 0 || y >= maps.size() || x >= maps[0].size())
            continue;

        if (maps[y][x] == 'X')
            continue;

        if (check[y][x] > 0)
            continue;

        que.push({ x,y });
        if (check[y][x] == 0)
            check[y][x] = check[curY][curX] + 1;
        else
            check[y][x] = min(check[y][x], check[curY][curX] + 1);
       /* if (y == endPos.second && x == endPos.first)
            return;*/
    }

    if (!que.empty())
    {
        pair<int, int> temp = que.front();
        que.pop();
        BFS(maps, temp, endPos);
    }
}

int solution(vector<string> maps) {
    int answer = 0;

    check.resize(maps.size(),vector<int>(maps[0].size(), false));
    int temp = 0;
    pair<int, int> start, pick, end;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'S')
                start = { j, i };
            if (maps[i][j] == 'L')
                pick = {j, i};
            if (maps[i][j] == 'E')
                end = { j, i };
        }
    }
    check[start.second][start.first] = 1;

    BFS(maps, start, pick);
    temp = check[pick.second][pick.first] == 0 ?  -1 : check[pick.second][pick.first] - 1;
    check.clear();

    check.resize(maps.size(), vector<int>(maps[0].size(), false));
    check[pick.second][pick.first] = 1;
    BFS(maps, pick, end);

    answer = check[end.second][end.first] == 0 ? -1 : check[end.second][end.first] - 1;

    if (temp == -1 || answer == -1)
        answer = -1;
    else
        answer += temp;


    return answer;
}

int main()
{
    solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });
}