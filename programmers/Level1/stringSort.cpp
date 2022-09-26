#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end());
    /*
    * sort(v.begin(), v.end(), greater<자료형>());//내림차순 (Descending order)
    sort(v.begin(), v.end(), less<자료형>());//오름차순 (default = Ascending order)
    */
    for (int i = s.size()-1; i >= 0; i--)
    {
        answer += s[i];
    }

    return answer;
}