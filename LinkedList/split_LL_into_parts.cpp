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
    float size(ListNode *head)
    {
        ListNode *t = head;
        float s = 0;
        while (t)
        {
            t = t->next;
            s++;
        }
        return s;
    }
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int s = size(head);
        vector<ListNode *> parts;
        ListNode *newPart = new ListNode(100);
        int partSize = round(s / k);
        int extraLen = s % k;
        ListNode *temp = newPart;
        while (head)
        {
            if (partSize)
                temp->next = new ListNode(head->val);
            else if (extraLen)
            {
                temp->next = new ListNode(head->val);
                parts.push_back(newPart->next);
                newPart = new ListNode(100);
                temp = newPart;
                partSize = round(s / k);
                head = head->next;
                extraLen--;
                continue;
            }
            else
            {
                parts.push_back(newPart->next);
                newPart = new ListNode(100);
                temp = newPart;
                partSize = round(s / k);
                continue;
            }
            partSize--;
            head = head->next;
            temp = temp->next;
        }
        if (newPart->next)
            parts.push_back(newPart->next);
        if (k > s)
        {
            while (k > s)
            {
                parts.push_back(NULL);
                k--;
            }
        }
        return parts;
    }
};