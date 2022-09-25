#include <string>
#include <vector>

using namespace std;

enum DAY
{
    FRI, SAT , SUN, MON, TUE, WED, THU
};

string solution(int a, int b) {
    string answer = "";

    int month[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    //string days[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    int num = 0;

    for (int i = 0; i < a; i++)
    {
        num += month[i];
    }
    num += b -1;
    DAY temp = (DAY)(num % 7);
    switch (temp)
    {
    case SUN:
        answer = "SUN";
        break;
    case MON:
        answer = "MON";
        break;
    case TUE:
        answer = "TUE";
        break;
    case WED:
        answer = "WED";
        break;
    case THU:
        answer = "THU";
        break;
    case FRI:
        answer = "FRI";
        break;
    case SAT:
        answer = "SAT";
        break;
    default:
        break;

    }

    //return days[(sum + b) % 7];

    return answer;
}