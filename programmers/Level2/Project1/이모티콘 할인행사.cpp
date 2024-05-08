#include <string>
#include <vector>
#include <iostream>
using namespace std;

int discount[] = { 10, 20, 30, 40 };
vector<pair<int, int>> emoticon_price(7, { 0 , 0 }); // {할인 된 가격, 할인률}
vector<int> answer = vector<int>(2, 0);

void dfs(int emoticon, int emoticon_count, vector<vector<int>> users, vector<int> emoticons)
{
    if (emoticon < emoticon_count)
    {
        // 할인률에 따른 이모티콘 가격 책정
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
            // 유저가 구입할 이모티콘들의 할인 된 값 구하기
            int total_price = 0;
            for (int j = 0; j < emoticon_count; ++j)
            {
                if (emoticon_price[j].second >= users[i][0])
                    total_price += emoticon_price[j].first;
            }

            // 유저가 구독할지 이모티콘들을 살지 구분하기
            if (total_price >= users[i][1])
                ++subscribe;
            else
                purchase_prices += total_price;
        }

        // 만약 가입자가 기존의 가입자 보다 많다면 정답으로 등록해둔다.
        if (subscribe > answer[0])
        {
            answer[0] = subscribe;
            answer[1] = purchase_prices;
        }
        // 가입자 수는 같은데 구매 비용이 더 높다면 정답으로 등록해둔다
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