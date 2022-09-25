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

 algorithm 헤더
  min_element(start, arrSize) : 최소값 반환
  max_element(start, arrSize) : 최대값 반환
  find(start, end, num) : num을 가진 주소지를 반환
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

