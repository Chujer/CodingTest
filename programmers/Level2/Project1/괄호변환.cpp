#include <string>
#include <vector>
#include <queue>

using namespace std;

string CheckTwo(string& data, string& v);

string CheckOne(string& data)
{
    if (data == "")
        return "";
    int left = 0, right = 0;
    int index = 0;
    bool isPerfect = true;
    queue<char> temp;
    string u = "", v = "";


    for (index; index < data.size(); index++)
    {
        if (data[index] == '(')
        {
            left++;
            temp.push(data[index]);
        }
        if (data[index] == ')')
        {
            right++;
            if (temp.empty())
                isPerfect = false;
            else
                temp.pop();
        }

        u += data[index];


        if (left == right)
        {
            break;
        }
    }

    v = data.substr(index+1, data.size());

    if (u == "" && v == "")
        return "";

    if (isPerfect)
    {
        return u + CheckOne(v);
    }
    else
    {
        return CheckTwo(u,v);
    }

}

string CheckTwo(string& data, string& v)
{
    string temp = "(";
    temp += CheckOne(v);
    temp += ')';

    data.pop_back();

    for (int i = 1; i < data.size(); i++)
    {
        if (data[i] == '(')
            temp += ')';
        else
            temp += ('(');
    }

    return temp;
}

string solution(string p) {
    string answer = "";

    if (p == "")
        return answer;

    answer = CheckOne(p);
    

    return answer;
}

int main()
{
    solution("(()())()");
}