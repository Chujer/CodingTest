#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<unsigned long long> temp = { 0,1,1 };

    for (int i = 3; i <= n; i++)
    {
        temp.push_back((temp[i - 1] + temp[i - 2]) % 1234567);
    }

    answer = temp[n];

    return answer;
}

//int main()
//{
//    solution(100000);
//
//    return 0;
//}