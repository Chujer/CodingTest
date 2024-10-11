#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dirX[4] = { -1,1,0,0 };
int dirY[4] = { 0,0,-1,1 };

vector<vector<bool>> check;
queue<pair<int, int>> que;

void Search(const vector<vector<int>>& land, int posX, int posY, map<int, int>& data, int& startX)
{
    data[startX]++;
    for(int i = 0; i < 4; i++)
    {
        int x = dirX[i] + posX;
        int y = dirY[i] + posY;
        if(y < 0 || y >= land.size() || x < 0 || x >= land[0].size())
            continue;
	    if(check[y][x] == false)
            continue;
        if(land[y][x] == 0)
            continue;;

        check[y][x] = false;
        que.push({ x,y });
    }
    while(!que.empty())
    {
        pair<int, int> temp = que.front();
        que.pop();
        Search(land, temp.first, temp.second, data, startX);
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    map<int, int> data;
    check.resize(land.size(), vector<bool>(land[0].size(), true));

    map<int, bool> prevPos;
    map<int, bool> pos;
    for(int j = 0 ; j < land[0].size(); j++)
    {
        pos = prevPos;
        prevPos.clear();
        for (int i = 0; i < land.size(); i++)
        {
            if(i < land.size() && land[i][j] == 1&&pos[i] == true)
            {
                data[j] += data[j - 1];
                while (i < land.size() && land[i][j] == 1)
                {
                    prevPos[i] = true;
                    i++;
                }
            }
            if (land[i][j] == 1)
            {
                check[i][j] = false;
                Search(land, j, i, data, j);
                check.clear();
                check.resize(land.size(), vector<bool>(land[0].size(), true));
                while (i < land.size() && land[i][j] == 1)
                {
                    prevPos[i] = true;
                    i++;
                }

            }
        }
    }

    for(pair<int,int> d : data)
    {
        answer = max(answer, d.second);
    }

    return answer;
}

int main()
{
    solution({ {1, 0, 1, 0, 1, 1} ,{1, 0, 1, 0, 0, 0},{1, 0, 1, 0, 0, 1},{1, 0, 0, 1, 0, 0},{1, 0, 0, 1, 0, 1},{1, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1} });
}