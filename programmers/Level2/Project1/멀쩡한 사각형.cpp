#include <vector>
#include <math.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long long solution(int w, int h) {
    long long answer = (long long)w * h;

    if (h > w)
    {
        int temp = w;
        w = h;
        h = temp;
    }
    
    int gc = gcd(w, h);
    int temp_w = w / gc;
    int temp_h = h / gc;
    int temp = temp_w + temp_h - 1;
    answer = w * h - gc * temp;

    return answer;
}

int main()
{
    solution(10000000, 1000000);
}