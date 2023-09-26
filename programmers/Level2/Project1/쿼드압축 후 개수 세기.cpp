#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Search(vector<vector<int>>& arr, int x, int y, int size, vector<int>& answer)
{
    int count = arr[y][x];
    bool isX = false;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (count != arr[i][j])
            {
                isX = true;
                break;
            }
        }
        if (isX)
            break;
    }

    if (isX)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                Search(arr, size * j / 2 + x, size * i / 2 + y, size / 2,answer);
            }
        }

    }
    else if (count == 1)
    {
        answer[1]++;
    }
    else if (count == 0)
        answer[0]++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);

    Search(arr, 0, 0, arr.size(), answer);


    return answer;
}

int main()
{
    solution({{1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 1, 1}} );
}