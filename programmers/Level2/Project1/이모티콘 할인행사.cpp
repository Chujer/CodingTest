#include <string>
#include <vector>
#include <iostream>
using namespace std;

int discount[] = { 10, 20, 30, 40 };
vector<pair<int, int>> emoticon_price(7, { 0 , 0 }); // {���� �� ����, ���η�}
vector<int> answer = vector<int>(2, 0);

void dfs(int emoticon, int emoticon_count, vector<vector<int>> users, vector<int> emoticons)
{
    if (emoticon < emoticon_count)
    {
        // ���η��� ���� �̸�Ƽ�� ���� å��
        for (int i = 0; i < 4; ++i)
        {
            emoticon_price[emoticon].first = (100 - discount[i]) * emoticons[emoticon] / 100;
            emoticon_price[emoticon].second = discount[i];
            dfs(emoticon + 1, emoticon_count, users, emoticons);
        }
    }
    else
    {
        int subscribe = 0;
        int purchase_prices = 0;

        for (int i = 0; i < users.size(); ++i)
        {
            // ������ ������ �̸�Ƽ�ܵ��� ���� �� �� ���ϱ�
            int total_price = 0;
            for (int j = 0; j < emoticon_count; ++j)
            {
                if (emoticon_price[j].second >= users[i][0])
                    total_price += emoticon_price[j].first;
            }

            // ������ �������� �̸�Ƽ�ܵ��� ���� �����ϱ�
            if (total_price >= users[i][1])
                ++subscribe;
            else
                purchase_prices += total_price;
        }

        // ���� �����ڰ� ������ ������ ���� ���ٸ� �������� ����صд�.
        if (subscribe > answer[0])
        {
            answer[0] = subscribe;
            answer[1] = purchase_prices;
        }
        // ������ ���� ������ ���� ����� �� ���ٸ� �������� ����صд�
        else if (subscribe == answer[0])
        {
            if (purchase_prices > answer[1])
                answer[1] = purchase_prices;
        }
        return;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    dfs(0, emoticons.size(), users, emoticons);
    return answer;
}