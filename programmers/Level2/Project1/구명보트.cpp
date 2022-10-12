#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int startIndex = 0;
    int endIndex = people.size()-1;
   
    while(true)
    {
        if (startIndex == endIndex)
        {
            answer++;
            break;
        }

        if (people[endIndex] <= limit / 2)
        {
            answer += ((endIndex - startIndex) + 1) / 2;
            answer += ((endIndex - startIndex) + 1) % 2;
            break;
        }

        if (people[endIndex] + people[startIndex] <= limit)
        {
            answer++;
            startIndex++;
            endIndex--;
            
            if (endIndex == startIndex)
                break;

            continue;
        }
        answer++;
        endIndex--;
    }


    return answer;
}

int main()
{
    solution({ 10,20,30,40,50,60,70}, 100);
    return 0;
}

/*
vector.erase�� log(n)�̱� ������ ȿ�������� ������ �����.
�׷����� �ð� ȿ�������� ������ ����

���� �ذ��Ȳ�� ����
vector.pop_back �� ����ص� �����Ͱ���
*/