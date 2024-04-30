#include <string>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

bool cmp(set<int> a, set<int> b)
{
    return a.size() > b.size();
}

int solution(vector<int> cards) {
    int answer = 0;

    vector<set<int>> data(cards.size() + 1);

    for (int i = 1; i - 1 < cards.size(); i++)
    {
        set<int> s;
        int index = i-1;

        while (s.find(cards[index]) == s.end())
        {
            s.insert(cards[index]);
            data[i].insert(cards[index]);
            index = cards[index]-1;
        }

    }
    sort(data.begin(), data.end(), cmp);
    data.erase(unique(data.begin(), data.end()), data.end());

    answer = data[0].size() * data[1].size();

    return answer;
}

int main()
{
    solution({ 8,6,3,7,2,5,1,4 });
}