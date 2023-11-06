#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> rooms;
    vector<int> data;

    for (int i = 0; i < book_time.size(); i++)
    {
        int start = 0, end = 0;
        string temp;
        temp = book_time[i][0].substr(0, 2);
        start += stoi(book_time[i][0].substr(0, 2)) * 60;
        start += stoi(book_time[i][0].substr(3, 2));
        temp = book_time[i][1].substr(0, 2);
        end += stoi(book_time[i][1].substr(0, 2)) * 60;
        end += stoi(book_time[i][1].substr(3, 2)) + 10;

        if (end < start)
            end += 24 * 60;

        rooms.push_back({ start, end });
    }
    sort(rooms.begin(), rooms.end(), cmp);

    for (int i = 0; i < rooms.size(); i++)
    {
        if (data.empty())
        {
            data.push_back(rooms[i].second);
            continue;
        }

        int j = 0;
        for (j; j < data.size(); j++)
        {
            if (data[j] <= rooms[i].first)
            {
                data[j] = rooms[i].second;
                break;
            }
        }
        if(j == data.size())
            data.push_back(rooms[i].second);
    }

    answer = data.size();

    return answer;
}

int main()
{
    solution({{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}} );
}