#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int xMaxSize = 0;
    int yMaxSize = 0;

    for (int i = 0; i <sizes.size(); i++)
    {
        if (xMaxSize < max(sizes[i][0], sizes[i][1]))
            xMaxSize = max(sizes[i][0], sizes[i][1]);
    }
    for (int i = 0; i < sizes.size(); i++)
    {
        if (yMaxSize < min(sizes[i][0], sizes[i][1]))
            yMaxSize = min(sizes[i][0], sizes[i][1]);
    }
    answer = xMaxSize * yMaxSize;

    return answer;
}

/*
* // min(), max()함수의 숙련도 부족
int solution(vector<vector<int>> sizes)
{
    int answer=0;

    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }
    answer=w*h;

    return answer;
}
*/
