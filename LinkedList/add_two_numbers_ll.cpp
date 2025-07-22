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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(100);
        ListNode *temp = ans;
        int carry = 0;
        while (l1 && l2)
        {
            int result = l1->val + l2->val + carry;
            carry = 0;
            if (result >= 10)
            {
                carry = 1;
                result -= 10;
            }
            ListNode *newNode = new ListNode(result);
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
        {
            while (l1)
            {
                int result = l1->val + carry;
                carry = 0;
                if (result >= 10)
                {
                    carry = 1;
                    result -= 10;
                }
                ListNode *newNode = new ListNode(result);
                temp->next = newNode;
                temp = temp->next;
                l1 = l1->next;
            }
        }
        if (l2)
        {
            while (l2)
            {
                int result = l2->val + carry;
                carry = 0;
                if (result >= 10)
                {
                    carry = 1;
                    result -= 10;
                }
                ListNode *newNode = new ListNode(result);
                temp->next = newNode;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return ans->next;
    }
};