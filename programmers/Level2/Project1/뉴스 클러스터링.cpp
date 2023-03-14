#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void PushStr(string& s,const char b,const char c)
{
    //대문자 변환
    char upperS1, upperS2;
    upperS1 = toupper(b);
    upperS2 = toupper(c);

    if (65 > upperS1 || 90 < upperS1 || 65 > upperS2 || 90 < upperS2)
        return;

    s.push_back(upperS1);
    s.push_back(upperS2);
}

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> JStr1;
    vector<string> JStr2;
    vector<string> temp;
    float total = 0;
    float cross = 0;

    for(int i =0; i < str1.size() -1 ;i++) 
    {
        string temp = "";

        PushStr(temp, str1[i], str1[i+1]);
        if(temp == "")
            continue;

        JStr1.push_back(temp);
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string temp = "";

        PushStr(temp, str2[i], str2[i + 1]);
        if (temp == "")
            continue;

        JStr2.push_back(temp);
    }

    if (JStr1.size() == 0, JStr2.size() == 0)
        return 65536;

    for(string s : JStr1)
    {
        if(find(JStr2.begin(),JStr2.end(),s) != JStr2.end())
        {
            cross+=1;
            JStr2.erase(find(JStr2.begin(), JStr2.end(), s));
        }
    }
    temp.insert(temp.end(),JStr1.begin(), JStr1.end());
    temp.insert(temp.end(),JStr2.begin(), JStr2.end());
    total = temp.size();

    answer = (cross / total) * 65536;

    return answer;
}

int main()
{
    solution("E=M*C^2", "e=m*c^2");
    return 0;
}