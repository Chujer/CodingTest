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
    pow(n,^n) : ^n��ŭ n���� �����Ѵ�.
    sqrt(n) : n�� �������� ���Ѵ�.
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