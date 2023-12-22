#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;


    answer += d / k * 2 + 1;
    long long maxD = (long long)d * d;

    for (int i = k; i <= d; i += k)
    {
        long long temp = (long long)i * i;
        long long maxY = maxD - temp;

        answer += (long long)sqrt(maxY) / k;
    }

    return answer;
}

int main()
{
    solution(2, 4);
}