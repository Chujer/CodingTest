#include <string>
#include <vector>

using namespace std;

/*
파보나치 수열의 개념을 조금더 공부할 필요가 있음
나는 바보 멍청이
*/

long long solution(int n) {
    long long answer = 0;

    vector<long long> fn(n + 1);
    fn[1] = 1;
    fn[2] = 2;

    for (int i = 3; i < n+1; i++)
    {
        fn[i] = (fn[i - 1] + fn[i - 2]) % 1234567;
    }

    return answer = fn[n];
}

int main()
{
    solution(5);
    return 0;
}