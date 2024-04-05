#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int n, vector<int> money) {
    int answer = 0;

    vector<int> DP(n+1, 0);

    DP[0] = 1;
    for (int j = 0; j < money.size(); j++)
    {
        for (int i = money[j]; i <= n; i++)
        {
            DP[i] += DP[i - money[j]];
        }
    }


    return DP[n];
}

int main()
{
    solution(5, { 1,2,5 });
}