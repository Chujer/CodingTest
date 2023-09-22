#include <string>
#include <vector>

using namespace std;

void Search(vector<vector<int>> arr, int x, int y, int size, int& answer)
{
    vector<vector<int>> tempArr(size, vector<int>(size));
    int count = 0;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            count += arr[i][j];
        }
    }

    if (count > 0 && count != size * 2)
    {
        for (int i = y; i < y + size; i++)
        {
            vector<int> temp;
            for (int j = x; j < x +size; j++)
            {
                temp.push_back(arr[i][j]);
            }
            tempArr.push_back(temp);
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                Search(arr, i * size / 2, j / size / 2, size / 2, answer);
            }
        }
    }

    answer++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    Search(arr, 0,0,arr.size(), )

    return answer;
}