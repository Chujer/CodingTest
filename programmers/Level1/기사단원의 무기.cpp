#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;

    int temp = 0;
    int data = 0;

    for (int i = 2; i <= number; i++)
    {
        for (int j = 1; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                if (j == data)
                    break;
                if (j*j == i && j != 1)
                {
                    temp++;
                }
                else
                {
                    temp += 2;
                    data = i / j;
                }
            }
        }
        data = 0;
        if (temp > limit)
            temp = power;
        //1, 2, 2, 3, 2, 4, 2, 4, 3, 4
        answer += temp;
        temp = 0;
    }

    return answer;
}

int main()
{
    solution(10,3,2);
}