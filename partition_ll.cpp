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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return head;
        if (!head->next)
            return head;
        ListNode *left = new ListNode(100);
        ListNode *temp_left = left;
        ListNode *right = new ListNode(100);
        ListNode *temp_right = right;
        while (head)
        {
            ListNode *newNode = new ListNode(head->val);
            if (head->val < x)
            {
                temp_left->next = newNode;
                temp_left = temp_left->next;
            }
            else
            {
                temp_right->next = newNode;
                temp_right = temp_right->next;
            }
            head = head->next;
        }
        left = left->next;
        right = right->next;
        temp_right->next = NULL;
        temp_left->next = right;
        if (left)
            return left;
        return right;
    }
};