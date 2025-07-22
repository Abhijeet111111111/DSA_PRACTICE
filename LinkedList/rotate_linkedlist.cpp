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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL or head->next == NULL)
            return head;
        int size = 0;
        ListNode *temp = head;
        while (temp->next)
        {
            size++;
            temp = temp->next;
        }
        temp->next = head;
        size++;
        k = k % size;
        temp = head;
        int n = size - k - 1;
        while (n)
        {
            n--;
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};