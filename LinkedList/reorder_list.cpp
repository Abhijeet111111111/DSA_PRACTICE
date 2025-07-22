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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next;
        ListNode *prev = slow;
        slow->next = NULL;
        while (curr)
        {
            ListNode *Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        ListNode *a = head;
        ListNode *b = prev;

        while (a && b)
        {
            ListNode *a_next = a->next;
            a->next = b;
            a = a_next;
            ListNode *b_next = b->next;
            b->next = a;
            b = b_next;
        }
    }
};