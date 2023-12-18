#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int colpos;

bool cmd(vector<int> a, vector<int> b)
{
    if (a[colpos] < b[colpos])
        return true;
    else if (a[colpos] == b[colpos])
    {
        if (a[0] > b[0])
            return true;
    }
    return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    colpos = col - 1;
    sort(data.begin(), data.end(), cmd);

    vector<int> mods;

    for (int i = row_begin - 1; i < row_end; i++)
    {
        int temp = 0;
        for (int j = 0; j < data[i].size(); j++)
        {
            temp += data[i][j] % (i + 1);
        }
        mods.push_back(temp);
    }

    answer = mods.front();

    for (int i = 1; i < mods.size(); i++)
    {
        answer = answer ^ mods[i];
    }

    return answer;
}
int main()
{
    solution({ {2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3} }, 2, 2, 3);
}