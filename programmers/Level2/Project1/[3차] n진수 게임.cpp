#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 ���� n
  �̸� ���� ������ ���� t
  ���ӿ� �����ϴ� �ο� m
  Ʃ���� ���� p

  
*/

string solution(int n, int t, int m, int p) {
    string answer = "";

    string numbers = "";

    numbers += "0";
    for (int i = 0; i < t*m; i++)
    {
        string temp = "";
        int number = i;


        while (number > 0)
        {
            int convertNum = number % n;
            if (convertNum > 9)
            {
                convertNum = 'A' + convertNum-10;
                char t = convertNum;
                temp+=t;
                number = number / n;
                continue;
            }
            temp += to_string(convertNum);
            number = number / n;
        }
        reverse(temp.begin(), temp.end());
        numbers += temp;
    }

    for (int i = p-1; i < numbers.size(); i+=m)
    {
        answer += numbers[i];
        if (answer.size() == t)
            return answer;
    }
    
    return answer;
}

int main()
{
    solution(16, 1000, 1, 1);

    return 0;
}