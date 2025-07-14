#include <iostream>
#include <vector>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *c = new ListNode(100);
        ListNode *temp = c;
        ListNode *a = list1;
        ListNode *b = list2;
        while (a && b)
        {
            if (a->val < b->val)
            {
                temp->next = a;
                temp = temp->next;
                a = a->next;
            }
            else
            {
                temp->next = b;
                temp = temp->next;
                b = b->next;
            }
        }
        if (a)
            temp->next = a;
        else
            temp->next = b;
        return c->next;
    }
};