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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        while (temp)
        {
            int val = temp->val;
            ListNode *wait = temp;
            while (temp && temp->val == val)
            {
                temp = temp->next;
            }
            wait->next = temp;
        }
        return head;
    }
};