#include<vector>
#include <unordered_map>
#include <map>
using namespace std;

struct Pos
{
    int x = 0;
    int y = 0;

    /*bool operator!=(Pos& pos)
    {
        return (pos.x != x && pos.y != y);
    }
    bool operator==(Pos& pos)
    {
        return (pos.x == x && pos.y == y);
    }*/
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    struct Pos position = {0,0};
    Pos StartPos = {0,0};
   // Pos EndPos = { maps[maps.size()].size(), maps.size()};
    
    map<Pos,bool> slot;

    slot.insert(make_pair(position, true));
    //while (position.x != EndPos.x)
    //{
    //    if (position.x == EndPos.x)
    //        return answer;

    //    if (position.x < maps[maps.size()].size() && maps[position.y][position.x+1] == 1)
    //    {
    //        Pos temp = position;
    //        temp.x += 1;
    //        if (slot.find(temp) == slot.end())
    //        {
    //            position.x += 1;
    //            //slot.insert(make_pair(position, true));
    //            answer++;
    //            continue;
    //        }
    //    }
    //    if (position.x > 0 && maps[position.y][position.x - 1] == 1)
    //    {
    //        Pos temp = position;
    //        temp.x -= 1;
    //        if (slot.find(temp) == slot.end())
    //        {
    //            position.x -= 1;
    //            //slot.insert(make_pair(position, true));
    //            answer++;
    //            continue;
    //        }
    //    }
    //    if (position.y < maps.size() && maps[position.y + 1][position.x] == 1)
    //    {
    //        Pos temp = position;
    //        temp.y += 1;
    //        if (slot.find(temp) == slot.end())
    //        {
    //            position.y += 1;
    //          //  slot.insert(make_pair(position, true));
    //            answer++;
    //            continue;
    //        }
    //    }
    //    if (position.y > 0 && maps[position.y - 1][position.x] == 1)
    //    {
    //        Pos temp = position;
    //        temp.x -= 1;
    //        if (slot.find(temp) == slot.end())
    //        {
    //            position.y -= 1;
    //           // slot.insert(make_pair(position, true));
    //            answer++;
    //            continue;
    //        }
    //    }

    //    answer = 0;
    //    position = StartPos;
    //}


    return answer;
}

int main()
{
    solution({ {1,0,1,1,1}, {1,0,1,0,1},{1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1} });
}