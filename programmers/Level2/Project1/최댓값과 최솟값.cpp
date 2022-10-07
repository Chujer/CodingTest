#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;

    while (s.find(' ') != string::npos)  //공백제거
    {
        numbers.push_back(stoi(s.substr(0, s.find(' '))));
        s.erase(s.begin(),s.begin()+s.find(' ')+1);
    }
    numbers.push_back(stoi(s));

    sort(numbers.begin(), numbers.end());

    answer += to_string(numbers.front()) + ' ' + to_string(numbers.back());
   
    return answer;
}

//int main()
//{
//    string s = "10 -2 3 -4";
//    solution(s);
//}