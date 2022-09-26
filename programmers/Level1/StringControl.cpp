#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    /*
    #include <isdigit>
        isdigit(int c) : ���� �Ǵ� �Լ�
    */

    if (s.size() != 4 && s.size() != 6)
    {
        return false; 
    }


    for (char c : s)
    {
        if ((int)c < 47 || (int)c >57)
            return false;
    }

    return answer;
}