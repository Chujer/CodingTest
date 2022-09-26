#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> temp;
    
    while (s.c_str() != "\0")
    {
        temp.push_back(s.substr(0, s.find(" ")));
        if (s.find(" ") == s.npos)
            break;
        s.erase(0,s.find(" ")+1);
    }

    for (string t : temp)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (t[i] > 96)
                    answer += t[i] - 32;
                else
                    answer += t[i];
            }
            else
            {
                if (t[i] < 91)
                    answer += t[i] + 32;
                else
                    answer += t[i];
            }
        }
        answer += " ";
    }
    answer.erase(answer.size()-1, 1);

    return answer;
}

/*
    include <ctype.h> : string�� ���ԵǾ�����
    toupper(int c) : �ƽ�Űǥ�� �̿��� �빮���ΰ�� �ҹ��ڷ� ����
    tolower(int c) : �ƽ�Űǥ�� �̿��� �ҹ����ΰ�� �빮�ڷ� ����

    toupper,tolower ��� ������ �ش��ϴ� ���ڰ� �ƴҰ�� �״�� ��ȯ�Ѵ�.
*/