#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string, int> aClothes;

    for (vector<string> t : clothes)
    {
        if (aClothes.find(t[1]) == aClothes.end())
            aClothes.insert(make_pair(t[1], 1));
        else
            aClothes[t[1]]++;
    }

    vector<int> temp;

    for(pair<string, int> c : aClothes)
    {
        temp.push_back(c.second);
    }
    

    for(int i =0; i<temp.size();i++)
    {
        int t = 1;
    	t = temp[i] * answer;
        answer += temp[i];
        answer += t;
    }

    return answer;
}

int main()
{
    /*solution({ {"crow_mask", "face"},
        {"blue_sunglasses", "face"},
        {"smoky_makeup", "face"} });*/
	solution({ {"yellow_hat", "headgear"},
        {"blue_sunglasses", "eyewear"},
        {"green_turban", "headgear"}});
}