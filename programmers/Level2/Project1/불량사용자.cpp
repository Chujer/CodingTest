#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<string>> combinations;

void findCombinations(vector<string>& users, vector<string>& banned_ids, int index, set<string>& current) 
{
    if (index == banned_ids.size()) 
    {
        if (current.size() == banned_ids.size()) 
        {
            combinations.insert(current);
        }
        return;
    }

    for (string user : users) 
    {
        if (user.size() == banned_ids[index].size())
        {
            bool isMatch = true;
            for (int i = 0; i < user.size(); i++)
            {
                if (banned_ids[index][i] != '*' && banned_ids[index][i] != user[i])
                {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch)
            {
                if (current.find(user) == current.end()) {
                    current.insert(user);
                    findCombinations(users, banned_ids, index + 1, current);
                    current.erase(user);
                }
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<string> users;

    set<string> current_combination;
    findCombinations(user_id, banned_id, 0, current_combination);

    return combinations.size();
}