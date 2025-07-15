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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = NULL;
        ListNode *Next;
        ListNode *curr = slow;
        while (curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        while (prev && head)
        {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};