#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct Link
{

    Link(int index, Link* prvLink = nullptr, Link* postLink = nullptr) : index(index), prvLink(prvLink), postLink(postLink) {}
    int index;
    Link* prvLink;
    Link* postLink;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<Link*> table(n);
    stack<Link*> remove;
    table[0] = new Link(1);

    for (int i = 1; i < n; i++)
    {
        table[i] = new Link(1, table[i - 1]);
        table[i - 1]->postLink = table[i];
    }
    Link* curLink = table[k];

    for (int i = 0; i < cmd.size(); i++)
    {
        int x = 0;
        if (cmd[i].size() >= 2)
            x = stoi(cmd[i].substr(2, cmd.size()));

        if (cmd[i][0] == 'D')
        {
            for (int i = 0; i < x; i++)
            {
                if (!curLink->postLink)
                    break;
                curLink = curLink->postLink;
            }
        }
        if (cmd[i][0] == 'U')
        {
            if (!curLink->prvLink)
                break;
            for (int i = 0; i < x; i++)
                curLink = curLink->prvLink;
        }
        if (cmd[i][0] == 'C')
        {
            remove.push(curLink);
            curLink->index = 0;

            if (curLink->postLink == nullptr && curLink->prvLink == nullptr)
                curLink = nullptr;
            else if (curLink->postLink == nullptr)  //현재가 마지막 노드
            {
                curLink->prvLink->postLink = nullptr;
                curLink = curLink->prvLink;
            }
            else if (curLink->prvLink == nullptr)   //현재가 처음 노드
            {
                curLink->postLink->prvLink = nullptr;
                curLink = curLink->postLink;
            }
            else
            {
                curLink->postLink->prvLink = curLink->prvLink;
                curLink->prvLink->postLink = curLink->postLink;
                curLink = curLink->postLink;
            }

        }
        if (cmd[i][0] == 'Z')
        {
            Link* temp = remove.top();
            temp->index = 1;
            remove.pop();
            if(temp->postLink != nullptr)
                temp->postLink->prvLink = temp;

            if (temp->prvLink != nullptr)
              temp->prvLink->postLink = temp;
        }
    }

    for (int i = 0; i < table.size(); i++)
    {
        if (table[i]->index == 1)
            answer += "O";
        else
            answer += "X";
    }

    return answer;
}


int main()
{
    solution(8, 0, { "C", "C", "Z"});
}