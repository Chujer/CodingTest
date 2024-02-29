#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int area_to_cover = 1; // 첫 번째 기지국 이전의 영역을 커버해야 합니다.

    for (int i = 0; i < stations.size(); i++) 
    {
        int start_of_station = stations[i] - w; // 기지국의 커버리지 시작 지점

        if (area_to_cover < start_of_station)
        { // 커버되지 않은 영역이 있는 경우
            int gap = start_of_station - area_to_cover; // 커버되지 않은 영역의 길이
            answer += ceil((double)gap / (w * 2 + 1)); // 필요한 기지국의 수
        }

        area_to_cover = stations[i] + w + 1; // 다음 커버해야 하는 영역
    }

    // 마지막 기지국 이후의 영역에 대한 처리
    if (area_to_cover <= n) 
    {
        int gap = n - area_to_cover + 1;
        answer += ceil((double)gap / (w * 2 + 1));
    }

    return answer;
}

int main()
{
    solution(10, { 1 }, 1);
}