#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end());
    /*
    * sort(v.begin(), v.end(), greater<�ڷ���>());//�������� (Descending order)
    sort(v.begin(), v.end(), less<�ڷ���>());//�������� (default = Ascending order)
    */
    for (int i = s.size()-1; i >= 0; i--)
    {
        answer += s[i];
    }

    return answer;
}