#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cCount = 0;
    int sCount = 0;

    for (char& c : s)
    {
        if (tolower(c) == 'p')
            cCount++;
        else if (tolower(c) == 'y')
            sCount++;
    }

    

    return cCount == sCount ? true : false;
}

int main()
{
    string s = "pPoooyY";

    solution(s);
}