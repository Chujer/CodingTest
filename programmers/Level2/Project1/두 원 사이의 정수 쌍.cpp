#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i < r2; i++)
    {
        long long maxR2 = floor(sqrt(pow(r2, 2) - pow(i, 2)));
        long long maxR1 = ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        if (r1 <= i)
            answer += maxR2 - maxR1 ;
        else
            answer += maxR2 - maxR1 + 1;
    }
    answer += r2 - r1 + 1;
    answer *= 4;
    

    return answer;
}

int main()
{
    solution(2, 3);
}