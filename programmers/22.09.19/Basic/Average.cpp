#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    int Sum = 0;

    for (int num : arr)
    {
        Sum += num;
    }

    /*
    * #include <numeric>
    * answer = accumulate(arr.begin(), arr.end(), 0);
    * accumulate : �迭�� ���� �����ִ� �Լ� �� ������ �ʰ��ϴ� ������ ���Ҷ��� �����ؾ��Ѵ�.
    */

    answer = (double)Sum / arr.size();

    return answer;
}

int main()
{

    return 0;
}