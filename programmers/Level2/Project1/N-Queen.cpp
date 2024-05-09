#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;
int boardSize = 0;
using namespace std;
map<pair<int,int>, int> check;

bool isAble(vector<vector<int>>& data, pair<int, int> pos)
{
    int x = pos.first;
    int y = pos.second;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[y][i] == 1)
            return false;
        if (data[i][x] == 1)
            return false;
    }

    for (int i = boardSize; i > -boardSize; i--)
    {
        if (y + i >= 0 && x + i >= 0 && y + i < boardSize && x + i < boardSize)
            if (data[y + i][x + i] == 1)
                return false;
        if (y - i >= 0 && y - i < boardSize && x + i >= 0 && x + i < boardSize)
            if (data[y - i][x + i] == 1)
                return false;
    }
    return true;
}


void DFS(vector<vector<int>>& data, int n, set<map<pair<int, int>, int>>& test)
{

    vector<vector<int>> curData = data;
    map<pair<int, int>, int> curCheck = check;

    if (n == boardSize)
    {
        test.insert(check);
        return;
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (check.find({ j, i }) != check.end())
                continue;
            if (!isAble(data, { j,i }))
                continue;

            data[i][j] = 1;
            check[{j, i}] = 1;

            DFS(data,n + 1,  test);
            data = curData;
            check = curCheck;
        }
    }
}


int solution(int n) {
    int answer = 0;
    vector<vector<int>> data(n,vector<int>(n));
    boardSize = n;
    set<map<pair<int, int>, int>> test;
    DFS(data, 0, test);
    answer = test.size();

    return answer;
}

int main()
{
    solution(4);
}