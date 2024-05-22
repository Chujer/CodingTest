#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;

    vector<int> temp(2);
    map<pair<int, int>, char> data; //-1 = x / 0 = ¾øÀ½ / 1 = O
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
            else if (board[i][j] == 'X')
                temp[1]++;

            if (curRawMark != board[i][j] || board[i][j] == '.')
                isRawEndGame = false;

            if (curColMark != board[j][i] || board[j][i] == '.')
                isColEndGame = false;

        }

        if (isRawEndGame == true)
        {
            winner = curRawMark;
            for (int j = 0; j < 3; j++)
            {
                if (data[{i, j}] == winner)
                    EndCount--;
                data[{i, j}] = winner;
            }
            EndCount++;
        }
        if (isColEndGame == true)
        {
            winner = curColMark;
            for (int j = 0; j < 3; j++)
            {
                if (data[{j, i}] == winner)
                    EndCount--;
                data[{j, i}] = winner;
            }
            EndCount++;
        }

    }

    if (board[1][1] == board[0][0] && board[1][1] == board[2][2] && board[1][1] != '.')
    {
        if (winner != board[1][1])
        {
            winner = board[1][1];
            EndCount++;
        }
    }
    if (board[1][1] == board[2][0] && board[1][1] == board[0][2] && board[1][1] != '.')
    {
        if (winner != board[1][1])
        {
            winner = board[1][1];
            EndCount++;
        }
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
    solution({ "OOO" , "XXO" , "XXO" });
    //solution({ "OOO" , "OXX" , "OXX" });
}