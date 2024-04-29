#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> data;

    while (true)
    {
        string temp;
        temp = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1, s.size());
        data.push_back(stoi(temp));
        if (s.find(" ") == string::npos)
        {
            temp = s.substr(0, s.find(" "));
            s = s.substr(s.find(" ") + 1, s.size());
            data.push_back(stoi(temp));
            break;
        }
    }

    int min = *min_element(data.begin(), data.end());
    int max = *max_element(data.begin(), data.end());

    answer = to_string(min) + " " + to_string(max);

    return answer;
}

int main()
{
    solution("1 2 3 4");
}
