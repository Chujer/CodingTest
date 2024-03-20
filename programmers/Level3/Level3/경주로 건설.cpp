#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum DIR
{
    LEFT, TOP, RIGHT, BOTTOM
};
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,-1,0,1 };


void Update(vector<vector<map<DIR, int>>>& DP, vector<vector<int>> board, pair<int,int> pos)
{
    for (pair<DIR, int> d : DP[pos.second][pos.first])
    {
        int cost = 100;
        for (int r = 0; r < 4; r++)
        {
            int x = pos.first + dirX[r];
            int y = pos.second + dirY[r];
            if (x == 4 && y == 4)
                int a = 0;
            if (x < 0 || x >= board.size() || y < 0 || y >= board.size() || board[y][x] == 1)
                continue;


            if (d.first != r)
                cost = 600;
            else
                cost = 100;

            if (DP[y][x][(DIR)r] == 0)
            {
                DP[y][x][(DIR)r] = d.second + cost;
                Update(DP, board, { x,y });
            }
            else if(DP[y][x][(DIR)r] > d.second + cost)
            {
                DP[y][x][(DIR)r] = d.second + cost;
                Update(DP, board, { x,y });
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 400000;

    vector<vector<map<DIR, int>>> DP(board.size(), vector<map<DIR, int>>(board.size()));
    DIR dir;
    DP[0][0][RIGHT] = 0;
    DP[1][0][BOTTOM] = 100;
    DP[0][1][RIGHT] = 100;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (board[i][j] == 1)
                continue;

            Update(DP, board, { j,i });
        }
    }

    for (pair<DIR, int> d : DP[DP.size() - 1][DP.size() - 1])
    {
        answer = min(answer, d.second);
    }

    return answer;
}

int main()
{
    solution({ {0, 0, 0, 0, 0, 0, 0, 1} ,{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1},{0, 0, 1, 0, 0, 0, 1, 0},{0, 1, 0, 0, 0, 1, 0, 0},{1, 0, 0, 0, 0, 0, 0, 0} });
}