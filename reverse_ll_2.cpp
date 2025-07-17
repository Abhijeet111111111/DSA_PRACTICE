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
    int size_ll(ListNode *head)
    {
        ListNode *temp = head;
        int s = 0;
        while (temp)
        {
            temp = temp->next;
            s++;
        }
        return s;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int s = size_ll(head);
        if (left == right)
            return head;
        if (head->next == NULL)
            return head;
        if (!head->next->next)
        {
            if (left == right)
            {
                return head;
            }
            ListNode *head_next = head->next;
            head->next->next = head;
            head->next = NULL;
            return head_next;
        }
        if (left == 1)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode *Next;
            while (left <= right)
            {
                Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next;
                left++;
            }
            head->next = curr;
            return prev;
        }
        ListNode *temp = head;
        int curr_idx = left;
        while (left > 2)
        {
            left--;
            temp = temp->next;
        }
        ListNode *prev = temp->next;
        ListNode *prev_1 = prev;
        ListNode *curr = temp->next->next;
        ListNode *Next;
        while (curr_idx < right)
        {
            curr_idx++;
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        if (right == s)
        {
            temp->next = prev;
            prev_1->next = NULL;
            return head;
        }

        temp->next->next = curr;
        temp->next = prev;
        return head;
    }
};