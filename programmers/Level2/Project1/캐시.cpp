#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> lru(cacheSize);

    for (string city : cities)
    {
        //std::transform(city.begin(), city.end(), city.begin(), tolower);
      
        transform(city.begin(), city.end(), city.begin(), tolower);

        //for (char& c : city)
        //    c = tolower(c);

        for (int i = 0; i < cacheSize; i++)
        {
            if (lru[i] == city)
            {
                string temp = lru[i];
                lru.erase(lru.begin() + i);
                lru.push_back(temp);
                answer++;

                break;
            }
            else if(i == cacheSize-1)
            {
                if (lru.size() == cacheSize)
                    lru.erase(lru.begin());

                lru.push_back(city);
                answer += 5;
            }
        }
    }

    if (cacheSize == 0)
        answer = cities.size() * 5;

    return answer;
}

int main()
{
    solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
}