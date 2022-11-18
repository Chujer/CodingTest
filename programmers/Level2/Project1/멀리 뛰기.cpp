#include <string>
#include <vector>

using namespace std;

/*
�ĺ���ġ ������ ������ ���ݴ� ������ �ʿ䰡 ����
���� �ٺ� ��û��
*/

long long solution(int n) {
    long long answer = 0;

    vector<long long> fn(n + 1);
    fn[1] = 1;
    fn[2] = 2;

    for (int i = 3; i < n+1; i++)
    {
        fn[i] = (fn[i - 1] + fn[i - 2]) % 1234567;
    }

    return answer = fn[n];
}

int main()
{
    solution(5);
    return 0;
}