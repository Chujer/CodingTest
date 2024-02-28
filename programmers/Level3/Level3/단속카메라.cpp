#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int>b)
{
    if (a[1] < b[1])
        return true;

    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), cmp);

    int minMax = routes[0][1];


    for (int i = 1; i < routes.size(); i++)
    {
        if (minMax < routes[i][0])
        {
            answer++;
            minMax = routes[i][1];
        }
    }

    return answer;
}


int main()
{
    solution({ {-20,-15} ,{-14,-5},{-18,-13},{-5,-3} });
}