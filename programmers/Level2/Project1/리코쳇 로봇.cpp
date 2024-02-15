#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

enum Dir {
    LEFT, RIGHT, TOP, DOWN
};

Dir direction[4] = { LEFT, RIGHT, TOP, DOWN };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

pair<int, int> Move(vector<string>& board, pair<int, int>& curPos, Dir dir)
{
    pair<int, int> prePos = curPos;
    int x = curPos.first;
    int y = curPos.second;
    while (true)
    {
        prePos = { x,y };
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || y < 0 || x >= board[0].size() || y >= board.size() || board[y][x] == 'D')
        {
            return prePos;
        }
    }
}

int solution(vector<string> board) {
    int answer = -1;
    queue<pair<pair<int, int>, int>> q; // ((x, y), time)
    unordered_set<int> visited;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                q.push({ {j, i}, 0 });
                visited.insert(i * board[0].size() + j);
                break;
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (board[cur.first.second][cur.first.first] == 'G')
        {
            answer = cur.second;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> temp = Move(board, cur.first, direction[i]);
            if (temp == cur.first)
                continue;
            if (visited.count(temp.second * board[0].size() + temp.first))
                continue;
            visited.insert(temp.second * board[0].size() + temp.first);
            q.push({ temp, cur.second + 1 });
        }
    }

    return answer;
}

int main()
{
    solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
}