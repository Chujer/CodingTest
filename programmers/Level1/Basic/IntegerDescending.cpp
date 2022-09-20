#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
* 문자열을 이용한 방식
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <functional>
    using namespace std;

    long long solution(long long n) {
        long long answer = 0;

        string str = to_string(n);
        sort(str.begin(), str.end(), greater<char>());
        answer = stoll(str);

        return answer;
    }

*/
long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    while (n > 0)
    {
        num.push_back(n % 10);
        n = n / 10;
    }
    
    sort(num.begin(), num.end());
    int temp = 1;

    for (int i : num)
    {
        answer += i * temp;
        temp *= 10;
    }

    return answer;
}

/*
    함수 solution은 정수 n을 매개변수로 입력받습니다. 
    n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 
    예를들어 n이 118372면 873211을 리턴하면 됩니다.
*/