#include <string>
#include <vector>
#include<algorithm>
#include <set>
#include <deque>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    deque<int> dq1, dq2;
    dq1.assign(queue1.begin(), queue1.end());
    dq2.assign(queue2.begin(), queue2.end());
    deque<int> origin1 = dq1;
    deque<int> origin2 = dq2;

    long long total1 = 0, total2 = 0;

    for (int i = 0; i < queue1.size(); i++)
    {
        total1 += queue1[i];
        total2 += queue2[i];
    }

    while (answer <= queue1.size() * 4)
    {
        if (total1 == total2)
            return answer;

        answer++;
        if (total1 > total2)
        {
            //1에서 지우기
            total1 -= dq1.front();
            total2 += dq1.front();
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        else if (total1 < total2)
        {
            //1에서 지우기
            total2 -= dq2.front();
            total1 += dq2.front();
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
    }
    return -1;
}

int main()
{
    solution({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 10 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 });
}