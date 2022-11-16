#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }


    while (b-a != 1 || (b % 2 != 0 && b - 1 == a))
    {
        int tempA = a % 2;
        int tempB = b % 2;
        a = (a / 2) + tempA;
        b = (b / 2) + tempB;
        answer++;
    }

    return answer;
}

int main()
{
    solution(16, 9, 7);
}