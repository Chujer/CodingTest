#include <iostream>
#include<string>
#include<stack>
using namespace std;

//int solution(string s)
//{
//    stack<char> c;
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (c.size() > 0)
//        {
//            if (c.top() == s[i])
//            {
//                c.pop();
//                continue;
//            }
//        }
//        c.push(s[i]);
//    }
//
//    if (c.size() == 0)
//        return 1;
//    else
//        return 0;
//}
int solution(string s)
{
    string c;

    for (int i = 0; i < s.size(); i++)
    {
        if (c.size() > 0)
        {
            if (c.back() == s[i])
            {
                c.erase(c.size() - 1);
                continue;
            }
        }
        c.push_back(s[i]);
    }

    if (c.size() == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int a =solution("abccde");
    return 0;
}

/*
stack은 처음사용해 보았다.
기존 사용하던 방식은 루프가 반복해서 되돌아가지만
stack을 이용하여 들어있는 데이터의 가짓수로 계산을 하였다

실험 결과
string을 stack과 같은방식으로 이용해보니 유사한 결과값으로 코딩테스트를 통과하는 모습을 보였다
*/