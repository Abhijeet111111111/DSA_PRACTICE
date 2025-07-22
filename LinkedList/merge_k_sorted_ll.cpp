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
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        ListNode *merged = mergeTwoLists(lists[0], lists[1]);

        for (int i = 2; i < lists.size(); i++)
        {
            merged = mergeTwoLists(merged, lists[i]);
        }
        return merged;
    }
};