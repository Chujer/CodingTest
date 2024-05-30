#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    if (begin == 1)
    {
        answer.push_back(0);
        begin++;
    }

    for (long long i = begin; i <= end; i++)
    {
        long long maxN = 1;
        for (long long j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                maxN = max(j, maxN);
                if (i / j <= 10000000)
                {
                    maxN = max(i / j, maxN);
                    break;
                }
            }
        }
        answer.push_back(maxN);
    }
    
    return answer;
} 


int main()
{
    solution(1,1);
}