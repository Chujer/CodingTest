#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> stageChallenger;
    map<int, int> stageFaild;
    map<int,float> temp;


    for (int i = 0; i < stages.size(); i++)
    {
        for (int j = 1; j <= stages[i]; j++)
        {
            stageChallenger[j]++;
        }
    }

    for (int stage : stages)
        if(stage <= N)
           stageFaild[stage]++;

    for (int i = 1; i <= N; i++)
    {
        if (stageChallenger[i] == 0)stageChallenger[i] = 1;
        temp[i] = (float)stageFaild[i] / (float)stageChallenger[i];
    }

    vector<pair<int, float>> tempData(temp.begin(), temp.end());
    sort(tempData.begin(), tempData.end(),comp);

    for (pair<int, float> t : tempData)
        answer.push_back(t.first);

    return answer;
}



/*
sort는 map도 사용할수있다
bool cmp(const pair<double,int>&a, const pair<double,int>&b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}
*/