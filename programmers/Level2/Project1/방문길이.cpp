#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    map<vector<vector<int>>, bool> newRoad;

    int x = 0;
    int y = 0;

    for (char d : dirs)
    {
        vector<vector<int>> road;
        road.push_back( { x, y });
        switch (d)
        {
        case 'U':
            if (y == 5)
                continue;
            y++;
            break;
        case 'D':
            if (y == -5)
                continue;
            y--;
            break;
        case 'L':
            if (x == -5)
                continue;
            x--;
            break;
        case 'R':
            if (x == 5)
                continue;
            x++;
            break;
        default:
            break;
        }
        road.push_back({ x, y });
        newRoad.insert(make_pair(road, true));
        reverse(road.begin(), road.end());
        newRoad.insert(make_pair(road, true));
    }
    answer = newRoad.size()/2;

    return answer;
}

int main()
{
    solution("LULLLLLLUD");
}