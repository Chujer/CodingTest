#include <string>
#include <vector>
#include <set>
#include <deque>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    k -= 1;
    vector<long long> people(n);
    deque<long long> temp;

    for (long long i = 0; i < people.size(); i++)
    {
        people[i] = i + 1;
    }

    long long test = 1;
    for (long long i = 1; i < n; i++)
    {
        test *= i;
        temp.push_front(test);
    }

    for (long long i = 0; i < temp.size(); i++)
    {
        long long index = k / temp[i];
        k = k % temp[i];

        answer.push_back(people[index]);
        people.erase(people.begin() + index);
    }
    answer.push_back(people.front());


    return answer;
}

long long main()
{
    solution(4, 24);
}