#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

   /* sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());*/

    map<int, int> loster;
    map<int, int> reserver;
    int answer = n;

    for (int i = 0; i < lost.size(); i++)
        loster[lost[i]] = lost[i];

    for (int i = 0; i < reserve.size(); i++)
        reserver[reserve[i]] = 2;


    for (pair<int, int> los : loster)
    {
        if (reserver[los.second] == 2 && loster[los.second] != 0)
        {
            reserver[loster[los.second]] = 1;
            loster[los.second] = 0;
        }
    }


    for (pair<int, int> los : loster)
    {
        if (loster[los.second] == 0) continue;

        if (reserver[(los.second - 1)] == 2)
        {
            reserver[(los.second - 1)] = 10;
            loster[los.second] = 0;
        }
        if (loster[los.second] == 0) continue;

        if (reserver[(los.second + 1)] == 2)
        {
            reserver[(los.second + 1)] = 1;
            loster[los.second] = 0;
        }
    }

    for (pair<int, int> los : loster)
    {
        if (los.second != 0)
            answer--;
    }

    return answer > n ? n : answer;
}

int main()
{
    solution(6, { 2, 4, 5 },
                 { 1, 3, 6 });
    //n= 6, lost = [2, 4, 5], reserve = [1, 3, 6] 일 경우 해당 테스트 에러뜨네요
    int a = 0;
}