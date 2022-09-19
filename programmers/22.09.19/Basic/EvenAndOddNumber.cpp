#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

string solution(int num) {
    string answer = "";

    //if (num % 2 == 0)
    //{
    //    answer = "Even";
    //}
    //else
    //    answer = "Odd";

    answer = num % 2 == 0 ? "Even" : "Odd";

    return answer;
}

int main()
{
    int num;
    string answer;
    cin >> num;

    answer = solution(num);

    cout << answer;
}