#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pNum = 0;
    int yNum = 0;
    for (char a : s)
    {
        if (a == 'p' || a == 'P')
            pNum++;
        if (a == 'y' || a == 'Y')
            yNum++;
    }

    if (pNum == yNum)
        answer = true;
    else
        answer = false;


    return answer;
}
/*
* ���� ����

    �빮�ڿ� �ҹ��ڰ� �����ִ� ���ڿ� s�� �־����ϴ�. s�� 'p'�� ������ 'y'�� ������ ���� ������ True, 
    �ٸ��� False�� return �ϴ� solution�� �ϼ��ϼ���. 'p', 'y' ��� �ϳ��� ���� ���� �׻� True�� �����մϴ�. 
    ��, ������ ���� �� �빮�ڿ� �ҹ��ڴ� �������� �ʽ��ϴ�.

    ���� ��� s�� "pPoooyY"�� true�� return�ϰ� "Pyy"��� false�� return�մϴ�.

  ���ѻ���

    ���ڿ� s�� ���� : 50 ������ �ڿ���
    ���ڿ� s�� ���ĺ����θ� �̷���� �ֽ��ϴ�.
*/