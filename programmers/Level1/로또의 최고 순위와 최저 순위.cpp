#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int minTemp = 0;
    int maxTemp = 0;
    int rank[7] = { 6,6,5,4,3,2,1 };
    int* answer = (int*)malloc(sizeof(minTemp) + sizeof(maxTemp));

    for (int i = 0; i < lottos_len; i++)
    {
        for (int j = 0; j < win_nums_len; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                minTemp++;
                maxTemp++;
            }
        }
        if (lottos[i] == 0)
            maxTemp++;
    }

    minTemp = rank[minTemp];
    maxTemp = rank[maxTemp];

    answer[0] = maxTemp;
    *(answer+1) = minTemp;

    return answer;
}

//int main()
//{
//    int a[] = { 44, 1, 0, 0, 31, 25 };
//    int b[] = { 31, 10, 45, 1, 6, 19 };
//    solution(a, 6, b, 6);
//}