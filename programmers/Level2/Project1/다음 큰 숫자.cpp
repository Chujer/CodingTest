#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
    int answer = 0;
    int nextNum = n+1;

    string temp;
    string temp2;
    int tempOne = 0;
    int temp2One = 0;

    while (n > 0)
    {
        if (n % 2 == 1)
            tempOne++;

        temp.insert(0, to_string(n % 2));
        n /= 2;
    }


    while (tempOne != temp2One)
    {
        temp2One = 0;
        temp2.clear();
        int count = nextNum;

        while (count > 0)
        {
            if (count % 2 == 1)
                temp2One++;

            temp2.insert(0, to_string(count % 2));
            count /= 2;
        }
        nextNum++;
    }
   
    answer = nextNum - 1;


    return answer;
}

int main()
{
    solution(15);
    return 0;
}