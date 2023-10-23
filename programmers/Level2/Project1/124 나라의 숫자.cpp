#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(int n) {
    string answer = "";
    deque<int> num;
    while (n != 0)
    {
        if (n % 3 == 0)
        {
            --n;
            num.push_front(4);
        }
        else
           num.push_front(n%3);
        n /= 3;
    }

    for (int n : num)
    {
        answer += to_string(n);
    }

    return answer;
}

int main()
{
    solution(15);
}