#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
���� ���� ���ں� = ���Ͼȸſ�� + (2��°*2)

��������� ���ں������� k�̻��� �ɋ�����

���� k�̻��� �ɶ����� ������ϴ� �ּ� Ƚ��

������ 2���� ������� ���ο� �����̵ȴ�
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