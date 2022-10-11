#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        while (temp < n)
        {
            temp += i + num;
            num++;
            if (temp == n)
            {
                answer++;
            }
        }
        temp = 0;
    }


    return answer;
}

//int main()
//{
//    solution(15);
//    return 0;
//}