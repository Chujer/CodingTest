#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<pair<set<int>,set<int>>> data(n+1);    //first = ���κ��� ���� �༮ second = ���� ���� ���� �༮

    for (int i = 0; i < results.size(); i++)
    {
        int winner = results[i][0];
        int loser = results[i][1];

        data[winner].first.insert(loser);
        for (int l :data[loser].first)      //loser���� ���� �༮��
        {
            data[winner].first.insert(l);   //loser���� ���ѳ༮���� winder ���ѳ༮�� �ִ´�.
            data[l].second.insert(winner);  //loser���� ���ѳ༮�鿡�� winer���� ���ѳ༮�����ִ´�.
            for (int w : data[winner].second)
            {
                data[l].second.insert(w);
            }
        }

        data[loser].second.insert(winner);
        for (int w : data[winner].second)   //winer���� ���� �༮��
        {
            data[loser].second.insert(w);   //winer���� �ڳ༮�� ���ο��� �̱�༮���ִ´�.
            data[w].first.insert(loser);    // winer���� ���� �༮�鿡�� ������ �ִ´�.
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