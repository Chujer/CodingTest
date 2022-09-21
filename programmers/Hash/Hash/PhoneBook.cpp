#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include<algorithm>

using namespace std;

//bool solution(vector<string> phone_book) {
//    bool answer = true;
//
//    vector<string> phonNum;
//
//    for (string num : phone_book)
//    {
//        while (num.find(' ') != string::npos)
//            num.erase(num.find(' '), 1);
//
//        phonNum.push_back(num);
//    }
//
//    sort(phone_book.begin(), phone_book.end());
//    sort(phonNum.begin(), phonNum.end());
//
//    for (string num : phone_book)
//    {
//        for (string temp : phonNum)
//        {
//            if(num[0] != temp[0])
//                continue;
//            if (num != temp)
//            {
//                if (num.find(temp) != string::npos)
//                {
//                    if (num.find(temp) != 0)
//                    {
//                        continue;
//                    }
//                    return false;
//                }
//            }
//        }
//    }
//
//    return true;
//}


//
bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for (int i = 0; i < phoneBook.size() - 1; i++)
    {
        string temp1 = phoneBook[i];
        string temp2 = phoneBook[i + 1].substr(0, phoneBook[i].size());
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<string> a = { "119","11956" };
    vector<string> b = { "123","456","789","159"};
    vector<string> c = { "1195524421", "97674223", "119" };
    vector<string> d = { "934793", "34", "44", "9347" };
    vector<string> e = { "119846", "153","119",  "9347"};
    
    cout << solution(e) ? "true" : "false";
}