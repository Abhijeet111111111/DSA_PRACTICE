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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        if (!head->next->next)
        {
            head->next->next = head;
            ListNode *l = head->next;
            head->next = NULL;
            return l;
        }
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};