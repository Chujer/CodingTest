#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (long long i = 1; i <= n; i++)
    {
        answer.push_back(x * i);
    }
    return answer;
}

/*
���� ����

�Լ� solution�� ���� x�� �ڿ��� n�� �Է� �޾�, 
x���� ������ x�� �����ϴ� ���ڸ� n�� ���ϴ� ����Ʈ�� �����ؾ� �մϴ�. 
���� ���� ������ ����, ������ �����ϴ� �Լ�, solution�� �ϼ����ּ���.
*/