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
            answer = "김서방은 " + to_string(count) + "에 있다";
            break;
        }
         count++;
    }
    

    return answer;
}