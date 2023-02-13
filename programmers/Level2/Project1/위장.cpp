#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string, vector<string>> hClothes;

    for (vector<string> t : clothes)
    {
        hClothes[t[1]].push_back(t[0]);
        answer++;   //�Ϸ翡 �ϳ��� �Ծ��ٴ� ����
    }

    int temp = 0;
    int sum = 1;

    if (hClothes.size() > 1)
    {
        for (pair<string, vector<string>> p : hClothes)
        {
            int a = p.second.size();
            sum += (p.second.size() - temp);
            temp++;
        }
        answer += sum;
    }
    return answer;
}

int main()
{
    solution({ {"yellow_hat", "headgear"},
        {"blue_sunglasses", "eyewear"},
        {"green_turban", "headgear"} });
}