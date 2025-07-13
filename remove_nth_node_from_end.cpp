#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        n = n + 1;
        while (fast && n)
        {
            fast = fast->next;
            n--;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (n)
            return head->next;
        slow->next = slow->next->next;
        return head;
    }
};