#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int area_to_cover = 1; // ù ��° ������ ������ ������ Ŀ���ؾ� �մϴ�.

    for (int i = 0; i < stations.size(); i++) 
    {
        int start_of_station = stations[i] - w; // �������� Ŀ������ ���� ����

        if (area_to_cover < start_of_station)
        { // Ŀ������ ���� ������ �ִ� ���
            int gap = start_of_station - area_to_cover; // Ŀ������ ���� ������ ����
            answer += ceil((double)gap / (w * 2 + 1)); // �ʿ��� �������� ��
        }

        area_to_cover = stations[i] + w + 1; // ���� Ŀ���ؾ� �ϴ� ����
    }

    // ������ ������ ������ ������ ���� ó��
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