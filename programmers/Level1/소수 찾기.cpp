#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool isprime = true;

    int temp = sqrt(n)+1;
    vector<int> element = {2};

    for (int i = 2; i <= temp; i++)         //������ ����
    {
        isprime = true;
        for (int j = 2; j < temp; j++)
        {
            if (i % j == 0 && i != j)
            {
                isprime = false;
                break;
            }
        }
        if (isprime == true)
        {
            element.push_back(i);
            answer++;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        isprime = true;
        for (int t : element)
        {
            if (i % t == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime == true)
            answer++;
    }

    

    return answer;
}


/*
�����佺�׳׽��� ü�� �̿��Ͽ� ����
�ٸ������ ó�� �������� ������ �ߴٷ��� ���Ѵٴ°� �ƽ���.
*/

/*
* 
* �Ʒ��� ��� �����ѻ���Ŭ�� �ڽ����� �������� ��簪�� false�����ν�
* ���ʿ��� ������ ���Ҽ� �ְ� �����Ͽ���.
int solution(int n) 
{
    int answer = 0;
    vector<bool> tmp(n + 1, true);

    for (int i = 2; i < n + 1; i++) {
        if (tmp[i] == true) 
        {
            for (int j = 2; i * j < n + 1; j++)
                tmp[i * j] = false;
            answer++;
        }
    }

    return answer;
}
*/
