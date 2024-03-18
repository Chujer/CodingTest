#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long left = 1;
    long long right = (long long)times.back() * n; 
    
    while (left <= right)
    {
        long long mid = (right + left) / 2;
        long long count = 0;

        for (int i = 0; i < times.size(); i++)
        {
            count += mid / times[i];
            if (count >= n)
                break;
        }

        if (count >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }



    return answer;
}

int main()
{
    solution(6, { 7,10 });
}