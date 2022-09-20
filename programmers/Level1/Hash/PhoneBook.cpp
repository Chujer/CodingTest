#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, string> phon;

    for (string temp : phone_book)
    { 
        for (pair<string,string>a : phon)
        {
            if (temp.find(a.second) != string::npos)
                return false;
        }
        phon.insert(make_pair(temp, temp));
    }

    return true;
}

int main()
{
    vector<string> a = { "119","11956" };
    vector<string> b = { "123","456" };
    vector<string> c = { "119","7546554","11 9 56"};
    cout << solution(b);
}