#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void Check(vector<vector<int>> land, int depth, int point, int maxPoint)
{

}

int solution(vector<vector<int> > land)
{
    int answer = 0;

    stack<int> landPoint;

    for (int i = 0; i < land.size(); i++)
    {
        int maxCount = 0;
        int index = 0;
        for (int j = 0; j < land[i].size(); j++)
        {
            if (land[i][j] > maxCount && (landPoint.empty() || j != landPoint.top()))
            {
                maxCount = land[i][j];
                index = j;
            }
        }
        landPoint.push(index);
        cout << landPoint.top();
        answer += maxCount;
    }
    return answer;
}

int main()
{
    solution({ { 5,3,2,1}, { 5,6,7,8 }, { 4,3,2,1 },{ 3,4,2,1 },{ 4,3,2,5 } ,{ 4,3,2,1 } });
}