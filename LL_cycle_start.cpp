#include <iostream>
#include<unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> set;
        while (head)
        {
            if (set.find(head) != set.end())
                return head;
            set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};