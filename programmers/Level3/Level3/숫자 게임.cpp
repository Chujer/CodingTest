#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    deque<int> aData(A.size()), bData(A.size());
    copy(A.begin(), A.end(), aData.begin());
    copy(B.begin(), B.end(), bData.begin());

    sort(aData.begin(), aData.end(), greater<>());
    sort(bData.begin(), bData.end(), greater<>());

    while(!aData.empty())
    {
        if (aData.front() > bData.front())
        {
            aData.pop_front();
            bData.pop_back();
        }
        else if (aData.front() == bData.front())
        {
            aData.pop_front();
            bData.pop_back();
        }
        else
        {
            aData.pop_front();
            bData.pop_front();
            answer++;
        }
    }

    return answer;
}

int main()
{
    solution({ 5,1,3,7 }, { 2,2,6,8 });
}