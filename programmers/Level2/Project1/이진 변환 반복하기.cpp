#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    string tempString;
    int tempNum = 0;

    while (s != "1")
    {
        for (char a : s)
        {
            if (a == '0')
            {
                answer[1]++;
                continue;
            }

            tempString.push_back(a);
        }
        tempNum = tempString.size();
        s = "";

        while (tempNum != 0)
        {
           s.insert(s.begin(), (char)tempNum % 2 + '0');
            tempNum /= 2;
        }

        tempString.clear();
        answer[0]++;
    }

    return answer;
}

//int main()
//{
//    string a = "110010101001";
//    solution(a);
//    return 0;
//}