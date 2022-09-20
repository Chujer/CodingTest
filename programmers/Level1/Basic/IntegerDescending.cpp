#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
* ���ڿ��� �̿��� ���
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
    �Լ� solution�� ���� n�� �Ű������� �Է¹޽��ϴ�. 
    n�� �� �ڸ����� ū�ͺ��� ���� ������ ������ ���ο� ������ �������ּ���. 
    ������� n�� 118372�� 873211�� �����ϸ� �˴ϴ�.
*/