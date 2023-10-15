#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool Compare(pair<string, set<pair<int, int>, greater<>>> a, pair<string, set<pair<int, int>, greater<>>> b)
{
    int subA = 0, subB = 0;
    for (pair<int, int> ta : a.second)
        subA = subA + ta.first;
    for (pair<int, int> tb : b.second)
        subB = subB + tb.first;

    return subA >subB;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, set<pair<int,int>,greater<>>> musics;

    for (int i = 0; i < genres.size(); i++)
    {
        musics[genres[i]].insert({ plays[i], i });
    }
    vector<pair<string, set<pair<int, int>, greater<>>> > sortedMusics(musics.begin(), musics.end());
    sort(sortedMusics.begin(), sortedMusics.end(), Compare);

    for (int i = 0; i < sortedMusics.size(); i++)
    {
        set<pair<int, int>>::iterator iter = sortedMusics[i].second.begin();
        if (sortedMusics[i].second.size() == 1)
        {
            answer.push_back((*iter++).second);
            continue;
        }
        pair<int, int> first = *iter++;
        pair<int, int> second = *iter;

        if (first.first == second.first)
        {
            answer.push_back(first.second > second.second ? second.second : first.second);
            answer.push_back(first.second > second.second ? first.second : second.second);
        }
        else
        {
            answer.push_back(first.second);
            answer.push_back(second.second);
        }
    }

    return answer;
}

int main()
{
    solution({ "classic", "pop", "classic", "classic"}, { 500, 600, 600, 500});
}