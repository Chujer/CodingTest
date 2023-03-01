#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long num = 1;
    long long indexNum = 0;

    long long temp = 0;

    vector<long long > tlong;

    if (left > n)
    {
        temp = left / n;
        num = temp+1;
        indexNum = temp * n;
    }

    for(long long i =temp; i<n;i++)
    {
        for(long long j = 0; j<n;j++)
        {

            if (indexNum >= left && indexNum <= right)
            {
                if (j <= i)
                    answer.push_back(num);
                else
                    answer.push_back(j + 1);
                
            }
            if (j <= i)
                tlong.push_back(num);
            else
                tlong.push_back(j + 1);

            
            indexNum++;
        }
        if (indexNum > right)
            break;
        num++;
    }
    
    return answer;
}

int main()
{
    solution(4, 7, 14);
    return 0;
}