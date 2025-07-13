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
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *tempA = head;
        ListNode *tempB = head->next;
        while (tempB && tempB->next)
        {
            if (tempA == tempB)
                return true;
            tempA = tempA->next;
            tempB = tempB->next->next;
        }
        return false;
    }
};