#include <string>
#include <vector>

using namespace std;

/*
// ���� �̿��� ���
bool solution(int x) {
    bool answer = true;
    int nTemp = x;
    int nSum = 0;
    while (nTemp > 0)
    {
        nSum += nTemp % 10;
        nTemp /= 10;
    }

    return x % nSum == 0 ? true : false;
}
*/
bool solution(int x) {
    bool answer = true;
    
    int sum = 0;

    string numS = to_string(x);
    for (int i = 0; i < numS.size(); i++)
    {
        sum += numS[i] - '0';
    }

     answer = (x % sum == 0) ? true : false;
    

    return answer;

}

/*
    * ���� ���� x�� �ϻ��� ���̷��� x�� �ڸ����� ������ x�� ���������� �մϴ�. 
    ���� ��� 18�� �ڸ��� ���� 1+8=9�̰�, 
    18�� 9�� ������ �������Ƿ� 18�� �ϻ��� ���Դϴ�. 
    �ڿ��� x�� �Է¹޾� x�� �ϻ��� ������ �ƴ��� �˻��ϴ� �Լ�, 
    solution�� �ϼ����ּ���.
*/