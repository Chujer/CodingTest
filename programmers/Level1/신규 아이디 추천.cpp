#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    string temp = "";

    for (char c : new_id)
    {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-' || c == '_' || c == '.')
        {
            if (c == '.')
            {
                if (temp.size() != 0 && temp[temp.size() - 1] == '.')
                    continue;
                if (temp.size() == 0)
                    continue;
            }
           
                 temp += tolower(c);
        }
    }

    if (temp[temp.size() - 1] == '.')
        temp.erase(temp.size() - 1);

    if (temp == "")
        temp += 'a';

    if (temp.size() > 15)
    {
        int a = temp.size() - 16;
        temp.erase(temp.begin() + 15,temp.end());
        if (temp[temp.size() - 1] == '.')
            temp.erase(temp.size() - 1);
    }

    if (temp.size() <= 2)
    {
        char plusChar = temp[temp.size() - 1];
        while (temp.size() <= 2)
            temp += plusChar;
    }

    answer = temp;

    return answer;
}
/*
'f...b' -> 'f.b ½ÇÇà½Ã 'f..b'
*/

int main()
{
    string a = "f.b.";
    solution(a);

    return 0;
}