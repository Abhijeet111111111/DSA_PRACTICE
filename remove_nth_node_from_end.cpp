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
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        if (size == 1)
            return NULL;
        size = size - n - 1;
        if (size == -1)
        {
            head = head->next;
            return head;
        }
        temp = head;
        while (size)
        {
            temp = temp->next;
            size--;
        }
        temp->next = temp->next->next;
        return head;
    }
};