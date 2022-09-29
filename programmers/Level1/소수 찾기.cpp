#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool isprime = true;

    int temp = sqrt(n)+1;
    vector<int> element = {2};

    for (int i = 2; i <= temp; i++)         //나눌수 저장
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
에라토스테네스의 체를 이용하여 구현
다른사람들 처럼 수학적인 공식을 잘다루지 못한다는게 아쉽다.
*/

/*
* 
* 아래의 경우 공식한사이클에 자신으로 나눠지는 모든값을 false함으로써
* 불필요한 연산을 안할수 있게 구현하였다.
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
