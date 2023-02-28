#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    map<int, int> tan;

    int bigger[2];

    for (int t : tangerine)
    {
        if (tan.find(t) == tan.end())
            tan.insert(make_pair(t,1));
        else
            tan[t]++;
    }

    vector<pair<int, int>> vec(tan.begin(), tan.end());

    sort(vec.begin(), vec.end(), cmp);
    

    for (int i = 0; i < vec.size(); i++)
    {
        k -= vec[i].second;
        answer++;
        if (k <= 0)
            break;
    }

    return answer;
}

int main()
{
    return solution(1, { 1, 1, 1, 1, 2, 2, 2, 3 });
}