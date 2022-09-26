#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp;
    vector<int> firstTernary;
    vector<int> nextTernary;
    for (int i = 1; true; i++)
    {
        if (pow(3, i) > n)
        {
            temp = i;
            break;
        }
    }

    // 3진법 변환
    firstTernary.resize(temp);
    firstTernary[firstTernary.size()-1] = n;
    for (int i = firstTernary.size()-1; i > 0; i--)
    {
        firstTernary[i - 1] = firstTernary[i] / 3;
        firstTernary[i] = firstTernary[i] % 3;
    }
    
    // 3진법 앞뒤 반전
    for (int i = firstTernary.size() - 1; i >= 0; i--)
    {
        nextTernary.push_back(firstTernary[i]);
    }
     
    //3진법 10진법 변환
    temp = 1;
    for (int i = nextTernary.size() - 1; i >= 0; i--)
    {
        answer+=nextTernary[i] * temp;
        temp *= 3;
    }
    return answer;
}

int main()
{
    solution(125);
    return 0;
}