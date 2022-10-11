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
stack�� ó������� ���Ҵ�.
���� ����ϴ� ����� ������ �ݺ��ؼ� �ǵ��ư�����
stack�� �̿��Ͽ� ����ִ� �������� �������� ����� �Ͽ���

���� ���
string�� stack�� ����������� �̿��غ��� ������ ��������� �ڵ��׽�Ʈ�� ����ϴ� ����� ������
*/