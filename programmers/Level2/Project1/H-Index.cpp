#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 설명을 이해를 몬하겠다;;
*/

int solution(vector<int> citations) {
    int answer = 0;    
    sort(citations.begin(), citations.end(), greater<>());
    int num = 0;

    for (int i = citations[0]; i >= 0; i--)
    {
        num = i;
        int count = 0;
        for(int cit : citations)
        {
            if (cit >= num)
                count++;
        }

        if (count >= num && citations.size() - count <= num)
            break;

    }
    answer = num;

    return answer;
}

int main()
{
    solution({ 6, 5, 5, 5, 3, 2, 1, 0 });
}