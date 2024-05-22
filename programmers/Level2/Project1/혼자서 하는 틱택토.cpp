#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;

    vector<int> temp(2);
    char winner = '.';
    int EndCount = 0;

    for (int i = 0; i < board.size(); i++)
    {
        char curRawMark = board[i][0];
        char curColMark = board[0][i];
        bool isRawEndGame = true;
        bool isColEndGame = true;
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 'O')
                temp[0]++;
            else if(board[i][j] == 'X')
                temp[1]++;
        }
        for (int j = 1; j < board.size(); j++)
        {
            if (curRawMark != board[i][j] || curRawMark == '.')
                isRawEndGame = false;

            if (curColMark != board[j][i] || curColMark == '.')
                isColEndGame = false;

            curRawMark = board[i][j];
            curColMark = board[j][i];
        }

        if (isColEndGame == true)
        {
            winner = curColMark;
            EndCount++;
        }
        if (isRawEndGame == true)
        {
            winner = curRawMark;
            EndCount++;
        }
    }

    if (board[1][1] == board[0][0] && board[1][1] == board[2][2] && board[1][1] != '.')
    {
        winner = board[1][1];
        EndCount++;
    }
    if (board[1][1] == board[2][0] && board[1][1] == board[0][2] && board[1][1] != '.')
    {
        winner = board[1][1];
        EndCount++;
    }

    if (EndCount > 1)
        return 0;
    if (EndCount == 1)
    {
        if (winner == 'O' && temp[0] == temp[1])
            return 0;
        if (winner == 'X' && temp[0] > temp[1])
            return 0;
    }

    if (temp[0] < temp[1])
        return 0;
    else if (temp[0] > temp[1] + 1)
        return 0;

    return answer;
}

int main()
{
    solution({ "XXO", "OOX", "XOX" });
}