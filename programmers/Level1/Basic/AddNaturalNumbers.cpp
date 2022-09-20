#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    int removeNum = 0;
    int temp = 10;
    while (temp)
    {
        if (temp > n)
        {
            answer += n / (temp / 10);
            break;
        } 
        int tempNum = n % temp;
        tempNum -= removeNum;
        removeNum = n % temp;

        answer += tempNum / (temp / 10);
        temp *= 10;
    }

    /*
    // ���������� ������ �������� ��ܿ��� ����� ������
    int solution(int n)
    {
        int answer = 0;
        while (n > 0) {
            answer += n % 10;
            n /= 10;
        }
        return answer;
    }

    //���ڿ��� ġȯ�� ����� ������
     string s = to_string(n);

      for(int i = 0; i < s.size(); i++) 
            answer += (s[i] - '0');
    */
    return answer;
}

int main()
{
    int a;
    a = solution(123);
    cout << a;
    return 0;
}
