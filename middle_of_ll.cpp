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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *tempNext = head;
        while (tempNext && tempNext->next)
        {
            temp = temp->next;
            tempNext = tempNext->next->next;
        }
        return temp;
    }
};