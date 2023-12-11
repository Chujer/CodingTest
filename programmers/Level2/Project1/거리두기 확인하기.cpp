#include <string>
#include <vector>

using namespace std;

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

void DFS(vector<string>& arr, vector<vector<bool>> check, int curX, int curY, bool isTable, bool& answer)
{
    check[curY][curX] = true;

    for (int i = 0; i < 4; i++)
    {
        int x = curX + dirX[i];
        int y = curY + dirY[i];
        if (x < 0 || x >= arr.size() || y < 0 || y >= arr.size())
            continue;

        if (arr[y][x] == 'X' || check[y][x] == true)    //파티션이거나 갔던곳이면 제외
            continue;

        if (arr[y][x] == 'O')
        {
            if (isTable == true)
                continue;

            DFS(arr, check, x, y, true, answer);
            continue;
        }

        if (arr[y][x] == 'P')
        {
            answer = false;
            return;
        }

        DFS(arr, check, x, y, false, answer);

    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<vector<bool>> check(5, vector<bool>(5, false));

    for (int i = 0; i < places.size(); i++)
    {
        bool temp = true;
        for (int j = 0; j < 5; j++)
        {
            for (int r = 0; r < 5; r++)
            {
                if(places[i][j][r] == 'P')
                    DFS(places[i], check, r, j, false, temp);
            }
        }
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    solution({{"XXXXX", "XXXXX", "XPPXX", "XXXXX", "XXXXX"}} );
}