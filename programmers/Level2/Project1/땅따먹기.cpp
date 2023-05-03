#include <iostream>
#include <vector>
using namespace std;
//문제오류 위에서 아래로 간다면서 아래에서 위로가는것도 만들어야함


int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i = 0; i < land.size() - 1; i++) {
        land[i + 1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i + 1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i + 1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i + 1][3] += max(land[i][0], max(land[i][1], land[i][2]));
    }
    answer = max(land[land.size() - 1][0], max(land[land.size() - 1][1], max(land[land.size() - 1][2], land[land.size() - 1][3])));
    return answer;
}

int main()
{
    solution({ {1,2,3,5}, {5,6,7,8}, {4,3,2,1}});
}