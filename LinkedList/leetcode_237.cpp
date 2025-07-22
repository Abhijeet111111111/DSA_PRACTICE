#include <iostream>
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
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node;
        while (temp->next->next)
        {
            swap(temp->val, temp->next->val);
            temp = temp->next;
        }
        swap(temp->val, temp->next->val);
        temp->next = NULL;
    }
};
