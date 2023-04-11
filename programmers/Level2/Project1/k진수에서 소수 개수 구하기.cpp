#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
/*
    �������� n�� �־�����. �̼��ڸ� k�� �ٲ����� ��ȯ�� �� �ȿ� �Ʒ� ���ǿ� �´� �Ҽ��� ����� �˾ƺ���

*/

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    string number = "";
    vector<long long> strs;

    while (n > 0)
    {
        number += to_string(n % k);
        n = n / k;
    }
    
    reverse(number.begin(), number.end());

    while (!number.empty())
    {
        string temp = "";
        for (char t : number)
        {
            if (!temp.empty() && t == '0')
            {
                number = number.substr(number.find(t)+1, number.size());
                if (temp != "1")
                    strs.push_back(stoll(temp));
                break;
            }
            else if (temp.empty() && t == '0')
            {
                number = number.substr(1, number.size());
                break;
            }


            if (number.find('0') == number.npos)
            {
                if (number != "1")
                    strs.push_back(stoll(number));
                number.clear();
                break;
            }
            temp += t;
        }
    }

    for (long long n : strs)
    {
        long long sq = sqrt(n);
        if (n == 2 || n == 3)
        {
            answer++;
            continue;
        }
        for (long long i = 2; i <= sq+1; i++)
        {
            if (n % i == 0)
                break;
            if (i == sq)
            {
                answer++;
                continue;
            }
        }
    }

    return answer;
}

int main()
{
    solution(3, 10);

    return 0;
}