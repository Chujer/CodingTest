#include <string>
#include <vector>

using namespace std;

int dirX[4] = { 0, 1, 0, 1 };
int dirY[4] = { 0, 0, 1, 1 };

vector<string> check;

void Search(vector<string> board,int curX, int curY)
{
    if (board[curY][curX] == '0')
        return;

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int x = curX + dirX[i];
        int y = curY + dirY[i];
        if (board[curY][curX] == board[y][x])
        {
            count++;
        }
    }
    if (count == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            int x = curX + dirX[i];
            int y = curY + dirY[i];
            check[y][x] = '1';
        }
    }
}

void MoveMap(vector<string>& board, int curX, int curY)
{
    int moveY = curY + 1;
    if (moveY >= board.size())
        return;
    if (board[moveY][curX] == '0')
    {
        board[moveY][curX] = board[curY][curX];
        board[curY][curX] = '0';
        MoveMap(board, curX, moveY);
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    check.resize(board.size(), string(board[0].size(), 0));

    int preScore = 0;

    do 
    {
        preScore = answer;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                Search(board, j, i);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i][j] == '1')
                {
                    board[i][j] = '0';
                    check[i][j] = 0;
                    answer++;
                }
            }
        }
        for (int i = m-2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                MoveMap(board, j, i);
            }
        }

    } while (preScore != answer);

    return answer;
}
int main()
{
    solution(6,6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" });
}