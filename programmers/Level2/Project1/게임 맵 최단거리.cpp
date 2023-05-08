#include<vector>
#include <map>
using namespace std;

void DFS(vector<vector<int>> maps, map<vector<int>, bool> prevPos, int nextX, int nextY, int& bestCount, int count)
{

    if (count >= bestCount)
        return;
    vector<int> temp;
    temp.push_back(nextX);
    temp.push_back(nextY);

    prevPos.insert(make_pair(temp, true));

    if (nextX == maps.size()-1 && nextY == maps[0].size()-1 && bestCount > count)
    {
        bestCount = count;
    }

    if(prevPos.find({nextX+1, nextY}) == prevPos.end() && nextX + 1 < maps.size() && maps[nextX + 1][nextY] == 1)
        DFS(maps, prevPos, nextX + 1, nextY, bestCount, count+1);

    if (prevPos.find({nextX - 1, nextY }) == prevPos.end() && nextX  != 0 && maps[nextX - 1][nextY] == 1)
        DFS(maps, prevPos, nextX - 1, nextY, bestCount, count+1);

    if (prevPos.find({ nextX, nextY + 1 }) == prevPos.end() && nextY + 1 < maps[0].size() && maps[nextX][nextY + 1] == 1)
        DFS(maps, prevPos, nextX, nextY + 1, bestCount, count+1);

    if (prevPos.find({ nextX, nextY - 1 }) == prevPos.end() && nextY != 0 && maps[nextX][nextY-1] == 1)
        DFS(maps, prevPos, nextX, nextY - 1, bestCount, count+1);
}

int solution(vector<vector<int> > maps)
{
    int answer = maps.size() * maps[0].size();

    int x = 0;
    int y = 0;

    map<vector<int>, bool> prevPos;
    int count = 1;
    DFS(maps, prevPos, x, y, answer, count);

    if (answer == maps.size() * maps[0].size())
        answer = -1;
    return answer;
}

int main()
{
    solution({ {1,0,1,1,1},{1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1} });

    return 0;
}