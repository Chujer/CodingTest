#include <string>
#include <vector>
#include <map>

using namespace std;

/*
    차들어오고, 나간기록이 주어졌을때, 차량별로 주차요금을 계산하게 한다. 
   fees  기본시간, 기본요금, 단위시간, 단위요금
   records string형 시간, 차량번호, 들어왔는지 나갔는지
*/

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, int> data;
    map<string, int> carFees;
    map<string, bool> carIsIn;

    for (string record : records)
    {
        int time = stoi(record.substr(0, 2)) * 60;
        time += stoi(record.substr(3, 2));

        string carNum = record.substr(6, 4);

        bool isIn = record.substr(11,3) == "IN" ? true : false;

        if (isIn == true)
        {
            if (data.find(carNum) == data.end())
                data.insert(make_pair(carNum, time));
            else
                data[carNum] = time - data[carNum];

            carIsIn[carNum] = true;
        }
        else
        {
            int addTime = time - data[carNum];
            data[carNum] = addTime;
            carFees[carNum] = fees[1];
            if (addTime > fees[0])
            {
                carFees[carNum] += ((addTime - fees[0]) / fees[2]) * fees[3];
                if ((addTime - fees[0]) % fees[2] != 0)
                    carFees[carNum] += fees[3];
            }
            carIsIn[carNum] = false;
        }
    }

    for (pair<string, bool> b : carIsIn)
    {
        if (b.second == true)
        {
            int addTime = (23*60) + 59 - data[b.first];
            data[b.first] = addTime;
            carFees[b.first] = fees[1];
            if (addTime > fees[0])
            {
                carFees[b.first] += ((addTime - fees[0]) / fees[2]) * fees[3];
                if ((addTime - fees[0]) % fees[2] != 0)
                    carFees[b.first] += fees[3];
            }
            carIsIn[b.first] = false;
        }
    }
    for (pair<string, int> f : carFees)
    {
        answer.push_back(f.second);
    }

    return answer;
}

int main()
{
    solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
}