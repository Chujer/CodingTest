#include <string>
#include <vector>

using namespace std;

/*
// 수를 이용한 방식
bool solution(int x) {
    bool answer = true;
    int nTemp = x;
    int nSum = 0;
    while (nTemp > 0)
    {
        nSum += nTemp % 10;
        nTemp /= 10;
    }

    return x % nSum == 0 ? true : false;
}
*/
bool solution(int x) {
    bool answer = true;
    
    int sum = 0;

    string numS = to_string(x);
    for (int i = 0; i < numS.size(); i++)
    {
        sum += numS[i] - '0';
    }

     answer = (x % sum == 0) ? true : false;
    

    return answer;

}

/*
    * 양의 정수 x가 하샤드 수이려면 x의 자릿수의 합으로 x가 나누어져야 합니다. 
    예를 들어 18의 자릿수 합은 1+8=9이고, 
    18은 9로 나누어 떨어지므로 18은 하샤드 수입니다. 
    자연수 x를 입력받아 x가 하샤드 수인지 아닌지 검사하는 함수, 
    solution을 완성해주세요.
*/