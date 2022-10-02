#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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