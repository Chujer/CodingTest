#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int count = 0;
    for (string temp : seoul)
    {
        if (temp.find("Kim") != string::npos)
        {
            answer = "�輭���� " + to_string(count) + "�� �ִ�";
            break;
        }
         count++;
    }
    

    return answer;
}