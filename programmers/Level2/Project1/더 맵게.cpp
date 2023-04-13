#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
섞은 음식 스코빌 = 제일안매운거 + (2번째*2)

모든음식의 스코빌지수가 k이상이 될떄까지

전부 k이상이 될때까지 섞어야하는 최소 횟수

섞으면 2개는 사라지고 새로운 음식이된다
*/

int solution(vector<int> scoville, int K) {
    int answer = 0;

    multiset<int> sc;
    sc.insert(scoville.begin(), scoville.end());

    multiset<int>::iterator iter = sc.begin();

    while (*iter < K)
    {
        if (sc.size() == 1)
        {
            return -1;
        }

        int temp = *iter + (*(++iter) * 2);
        sc.erase(sc.begin());
        sc.erase(sc.begin());
        sc.insert(temp);
        iter = sc.begin();
        answer++;
    } 

    return answer;
}

int main()
{
    solution({ 1, 2, 3, 9, 10, 12 }, 7);

    return 0;
}