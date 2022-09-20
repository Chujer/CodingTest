#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    string num;
    num = to_string(n);
    for (int i = num.size(); i > 0; i--)
    {
        answer.push_back(num[i-1] - '0');
    }

    return answer;
}
int main()
{
    vector<int> a;
    a = solution(12345);
    for (int i : a)
    {
        cout << i;
    }
    return 0;
}