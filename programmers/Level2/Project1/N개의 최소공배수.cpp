#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len�� �迭 arr�� �����Դϴ�.
int solution(int arr[], size_t arr_len) {
    int answer = arr[0];

    for (int i = 1; i < arr_len; i++)
    {
        int temp = 1;
        while (true)
        {

        }

        answer *= arr[i];
    }

    return answer;
}

int main()
{
    int arr[4] = { 2,6,8,14 };
    solution(arr, 4);
    return 0;
}