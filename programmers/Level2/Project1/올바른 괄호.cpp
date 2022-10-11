#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int start = 0;
    
    if (s.front() == ')')
        return false;

    for (char c : s)
    {
        if (c == '(')
            start++;
        else if (c == ')')
        {
            start--;
            if (start < 0)
                return false;
        }
    }
    if (start == 0)
        return true;

    return false;
}

