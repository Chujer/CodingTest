#include <string>
#include <vector>
#include<deque>

using namespace std;

int DP[1000001];
int DP2[1000001];
int endDP[1000001];

int solution(vector<int> money) {
    int answer = 0;

    vector<int>::iterator iter = money.end();
    vector<int> money1(money.begin(), --iter);
    deque<int> money2(money.begin(), --iter);
    money2.push_front(money.back());
    DP[0] = 0;
    DP[1] = money1[0];

    DP2[0] = 0;
    DP2[1] = money2[0];
    endDP[0] = max(DP[0], DP2[0]);
    endDP[0] = max(DP[1], DP2[1]);

    for (int i = 2; i <= money1.size(); i++)
    {
        DP[i] = max(money1[i - 1] + DP[i - 2], DP[i - 1]);
        DP2[i] = max(money2[i - 1] + DP2[i - 2], DP2[i - 1]);
        endDP[i] = max(DP[i], DP2[i]);
    }

    answer = endDP[money.size()-1];

    return answer;
}

int main()
{
    solution({ 4,3,2,1,3,5 });
}