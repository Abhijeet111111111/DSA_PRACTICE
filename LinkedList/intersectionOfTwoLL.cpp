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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int size_of_A = 0;
        int size_of_B = 0;
        ListNode *temp_a = headA;
        ListNode *temp_b = headB;
        while (temp_a)
        {
            size_of_A++;
            temp_a = temp_a->next;
        }
        while (temp_b)
        {
            size_of_B++;
            temp_b = temp_b->next;
        }
        if (size_of_A > size_of_B)
        {
            int gap = size_of_A - size_of_B;
            while (gap)
            {
                gap--;
                headA = headA->next;
            }
        }
        else if (size_of_A < size_of_B)
        {
            int gap = size_of_B - size_of_A;
            while (gap)
            {
                gap--;
                headB = headB->next;
            }
        }
        while (headA)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};