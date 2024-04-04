#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<pair<set<int>,set<int>>> data(n+1);    //first = 본인보다 약한 녀석 second = 본인 보다 강한 녀석

    for (int i = 0; i < results.size(); i++)
    {
        int winner = results[i][0];
        int loser = results[i][1];

        data[winner].first.insert(loser);
        for (int l :data[loser].first)      //loser보다 약한 녀석들
        {
            data[winner].first.insert(l);   //loser보다 약한녀석들을 winder 약한녀석에 넣는다.
            data[l].second.insert(winner);  //loser보다 약한녀석들에게 winer보다 강한녀석들을넣는다.
            for (int w : data[winner].second)
            {
                data[l].second.insert(w);
            }
        }

        data[loser].second.insert(winner);
        for (int w : data[winner].second)   //winer보다 강한 녀석들
        {
            data[loser].second.insert(w);   //winer보다 쌘녀석을 본인에게 이긴녀석에넣는다.
            data[w].first.insert(loser);    // winer보다 강한 녀석들에게 진놈을 넣는다.
            for (int l : data[loser].first)
            {
                data[w].first.insert(l);
            }
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first.size() + data[i].second.size() == n - 1)
            answer++;
    }

    return answer;
}

int main()
{
    solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}