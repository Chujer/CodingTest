#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum Dir
{
    RIGHT = 0, DOWN, LEFT, UP, END
};

int Swap(vector<vector<int>>& arr,vector<int> range)
{
    int curPosX = range[1];
    int curPosY = range[0];
    int nextX = curPosX;
    int nextY = curPosY;
    Dir direction = RIGHT;

    int tempNum = 0;
    int answer = arr.size() * arr[0].size();
    int nextNum = 0;
    tempNum = arr[curPosY][curPosX];
    while (direction != END)
    {
        switch (direction)
        {
        case RIGHT:
            if (nextX == range[3])
            {
                direction = DOWN;
                continue;
            }
            else
                nextX = curPosX + 1;
            break;
        case DOWN:
            if (nextY == range[2])
            { 
                direction = LEFT;
                continue;
            }
            else
                nextY = curPosY + 1;
            break;
        case LEFT:
            if (nextX == range[1])
            {
                direction = UP;
                continue;
            }
            else
                nextX = curPosX - 1;
            break;
        case UP:
            if (nextY ==  range[0])
            {
                direction = END;
                continue;
            }
            else
                nextY = curPosY - 1;

            break;
        default:
            break;
        }
        nextNum = arr[nextY][nextX];
        if (tempNum == 5)
            int b = 0;
        arr[nextY][nextX] = tempNum;
        tempNum = nextNum;
        answer = min(tempNum, answer);

        curPosX = nextX;
        curPosY = nextY;
    }

    return answer;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> arr(rows+1, vector<int>(columns+1));
    int count = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < arr[0].size(); j++)
        {
            arr[i][j] = count;
            count++;
        }
    }

    cout << endl << endl;

    for (int i = 0; i < queries.size(); i++)
    {
        answer.push_back(Swap(arr, queries[i]));
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    solution(6, 6, { {2,2,5,4} ,{3,3,6,6},{5,1,6,3} });
}