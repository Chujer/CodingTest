#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> comp;
    
    for (int i = 0; i < completion.size(); i++)
        comp[completion[i]]++;

    for(string p : participant)
    {
        if (comp[p] < 1)
        {
            answer = p;
            break;
        }
        comp[p]--;
    }

    return answer;
}