#include <string>
#include <vector>

using namespace std;

/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    int nMin = *min_element(arr.begin(), arr.end());
    int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();
    answer.erase(answer.begin() + pos);

    return answer.empty() ? vector<int>(1, -1) : answer;
}

 algorithm ���
  min_element(start, arrSize) : �ּҰ� ��ȯ
  max_element(start, arrSize) : �ִ밪 ��ȯ
  find(start, end, num) : num�� ���� �ּ����� ��ȯ
*/

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int findNum = 0;
    int min = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            findNum = i;
        }
        answer.push_back(arr[i]);
    }

    answer.erase(answer.begin() + findNum);

    if (answer.size() == 0)
        answer.push_back(-1);

    return answer;
}

