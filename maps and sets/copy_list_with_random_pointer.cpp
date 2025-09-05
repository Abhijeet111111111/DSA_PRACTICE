#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> node_pair;
        Node *cpy = new Node(999);
        Node *c_temp = cpy;
        Node *temp = head;
        while (temp)
        {
            c_temp->next = new Node(temp->val);
            c_temp = c_temp->next;
            temp = temp->next;
        }
        Node *c_head = cpy->next;

        c_temp = c_head;
        temp = head;

        while (temp)
        {
            node_pair[temp] = c_temp;
            c_temp = c_temp->next;
            temp = temp->next;
        }

        for (auto ele : node_pair)
        {
            if (ele.first->random)
                ele.second->random = node_pair[ele.first->random];
        }

        return c_head;
    }
};