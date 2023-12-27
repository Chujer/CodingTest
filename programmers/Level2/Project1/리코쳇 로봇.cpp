#include <string>
#include <vector>

using namespace std;
enum Dir {
    LEFT, RIGHT, TOP, DOWN
};

Dir direction[4] = { LEFT, RIGHT, TOP, DOWN };

pair<int, int> Move(vector<string>& board, pair<int, int>& curPos, Dir dir)
{
    pair<int, int> prePos = curPos;
    int x = curPos.first;
    int y = curPos.second;
    while (true)
    {
        prePos = { x,y };
        switch (dir)
        {
        case LEFT:
            x -= 1;
            break;
        case RIGHT:
            x += 1;
            break;
        case TOP:
            y -= 1;
            break;
        case DOWN:
            y += 1;
            break;
        default:
            break;
        }
        if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size() || board[y][x] == 'D')
        {
            return prePos;
        }
    }
}

void DFS(vector<string>& board,vector<vector<int>> check, pair<int, int> curPos, int& answer)
{
    if (answer != -1)
    {
        if (check[curPos.second][curPos.first] > answer)
            return;
        if (board[curPos.second][curPos.first] == 'G')
            answer = min(answer, check[curPos.second][curPos.first] - 1); 
    }
    else
        if (board[curPos.second][curPos.first] == 'G')
        {
            answer = check[curPos.second][curPos.first] - 1;
            return;
        }



    for (int i = 0; i < 4; i++)
    {
        pair<int,int> temp = Move(board, curPos, direction[i]);
        if (temp == curPos)
            continue;
        if (check[temp.second][temp.first] != 0)
            continue;
        check[temp.second][temp.first] = check[curPos.second][curPos.first] + 1;
        DFS(board, check, temp, answer);
    }
}

int solution(vector<string> board) {
    int answer = -1;

    vector<vector<int>> check(board.size(), vector<int>(board[0].size(), 0));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                check[i][j] = 1;
                DFS(board, check, {j,i}, answer);
            }
        }
    }

    

    return answer;
}

int main()
{
    solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
}