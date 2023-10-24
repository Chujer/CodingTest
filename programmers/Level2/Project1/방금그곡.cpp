#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    vector<int> times(musicinfos.size());
    vector<string> melodys(musicinfos.size());
    vector<string> names(musicinfos.size());

    for (int i = 0; i < musicinfos.size(); i++) //문자열 나누기
    {
        int start = stoi(musicinfos[i].substr(0, musicinfos[i].find(':'))) * 60;
        musicinfos[i] = musicinfos[i].substr(musicinfos[i].find(':')+1, musicinfos[i].size());
        start += stoi(musicinfos[i].substr(0, musicinfos[i].find(','))) ;
        musicinfos[i] = musicinfos[i].substr(musicinfos[i].find(',') + 1, musicinfos[i].size());

        int end = stoi(musicinfos[i].substr(0, musicinfos[i].find(':'))) * 60;
        musicinfos[i] = musicinfos[i].substr(musicinfos[i].find(':') + 1, musicinfos[i].size());
        end += stoi(musicinfos[i].substr(0, musicinfos[i].find(',')));
        musicinfos[i] = musicinfos[i].substr(musicinfos[i].find(',')+1,musicinfos[i].size());

        times[i] = end - start;
        names[i] = musicinfos[i].substr(0,musicinfos[i].find(',') );
        string temp = musicinfos[i].substr(musicinfos[i].find(',') + 1, musicinfos[i].size());

        vector<int> tempTime = times;
        for (int j = 0; j < tempTime[i]; j++)
        {
            if (temp[j % temp.size()] == '#')
                continue;

            if (temp[(j + 1) % temp.size()] == '#')
            {
                melodys[i] += temp[j % temp.size()] + 13;
                tempTime[i]++;
            }
            else
                melodys[i] += temp[j % temp.size()];
        }
    }

    int index = -1;

    for (int i = m.size() - 1; i >= 0; i--)
    {
        if (m[i] == '#')
        {
            m[i - 1] = m[i - 1] + 13;
            m.erase(m.begin()+i);
        }
    }

    for (int i = 0; i < melodys.size(); i++)
    {
        if (melodys[i].find(m) == string::npos)
            continue;

        if (index == -1)
            index = i;
        else
        {
            if (times[i] > times[index])
                index = i;
        }
    }
    if (index == -1)
        answer = "(None)";
    else
        answer = names[index];

    return answer;
}

int main()
{
    solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });
}