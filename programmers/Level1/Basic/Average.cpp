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
    * accumulate : 배열의 합을 구해주는 함수 단 범위를 초과하는 값들을 더할때는 주의해야한다.
    */

    answer = (double)Sum / arr.size();

    return answer;
}

int main()
{

    return 0;
}