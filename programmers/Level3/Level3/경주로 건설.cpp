#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum DIR
{
    LEFT, TOP, RIGHT, BOTTOM
};
int dirX[4] = { -1,0,1,0 };
int dirY[4] = { 0,-1,0,1 };

void Update(vector<vector<pair<int, vector<DIR>>>>& DP, vector<vector<int>>& board, vector<int> pos,vector<DIR> dir)
{
    for (int r = 0; r < 4; r++)
    {
        int plusCost = 100;
        int x = pos[0] + dirX[r];
        int y = pos[1] + dirY[r];

        if (y < 0 || y >= board.size() || x < 0 || x >= board.size())
            continue;

        if (x == 4 && y == 3)
            int a = 0;
        if (board[y][x] == 1)
            continue;


        if (find(DP[pos[1]][pos[0]].second.begin(), DP[pos[1]][pos[0]].second.end(), r) == DP[pos[1]][pos[0]].second.end())
        {
            plusCost = 600;
        }

        if (DP[y][x].first > DP[pos[1]][pos[0]].first + plusCost)
        {
            DP[y][x].first = DP[pos[1]][pos[0]].first + plusCost;
            DP[y][x].second.clear();
            DP[y][x].second.push_back((DIR)(r));
            Update(DP, board, { x,y }, DP[y][x].second);
        }
        else if (DP[y][x].first == DP[pos[1]][pos[0]].first + plusCost)
        {
            DP[y][x].first = DP[pos[1]][pos[0]].first + plusCost;
            DP[y][x].second.push_back((DIR)(r));
        }
    }

}

int solution(vector<vector<int>> board) {
    int answer = 0;

    vector<vector<pair<int, vector<DIR>>>> DP(board.size(), vector<pair<int, vector<DIR>>>(board.size(), { 500000, {RIGHT} }));

    DP[0][0] = { 0, {RIGHT} };
    DP[0][1] = { 100, {RIGHT} };
    DP[1][0] = { 100, {BOTTOM }};

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 1)
                continue;

            Update(DP, board, { j,i }, DP[i][j].second);
        }
    }


    answer = DP[board.size() - 1][board.size() - 1].first;

    return answer;
}

int main()
{
    solution({ {0, 0, 0, 0, 0} ,{0, 1, 1, 1, 0},{0, 0, 1, 0, 0},{1, 0, 0, 0, 1},{0, 1, 1, 0, 0} });
}