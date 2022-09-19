#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int temp;
    temp = sqrt(n);
    if(pow(temp,2) != n)
        return -1;
    temp += 1;
    answer = pow(temp,2);


    /*
    long long answer = sqrt(n);
    return pow(temp,2) == 2 ? pow(temp+1,2) : -1;
    
    #include <cmath>
    pow(n,^n) : ^n만큼 n값을 제곱한다.
    sqrt(n) : n의 제곱근을 구한다.
    */
    return answer;
}

int main()
{
    float temp;
    temp = solution(3);
    cout << temp;
    return 0;
}