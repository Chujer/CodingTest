//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> numbers, int target) {
//    int answer = 0;
//
//    vector<int> tempVector;
//
//    tempVector.insert(tempVector.end(),numbers.begin(),numbers.end());
//    int minusCount = 0;
//	vector<int> minusIndex(numbers.size(),1);
//    vector<int> baseIndex(numbers.size(), 1);
//    vector<vector<int>> minusIndexs;
//
//   // minusIndexs.push_back(minusIndex);
//
//    int tempCount = 0;
//    for(;minusCount<numbers.size();minusCount++)
//    {
//        for (int i = 0; tempCount < minusCount; i++)
//        {
//	        if(minusIndex[i%numbers.size()] == -1)
//                continue;
//
//            minusIndex[i % numbers.size()] = -1;
//            tempCount++;
//
//            if(tempCount == minusCount)
//            {
//                minusIndexs.push_back(minusIndex);
//                minusIndex = baseIndex;
//            }
//        }
//        tempCount = 0;
//        
//    }
//
//    return answer;
//}
//int main()
//{
//    solution({ 4,1,2,1 }, 4);
//    return 0;
//}