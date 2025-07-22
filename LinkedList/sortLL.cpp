#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *sortList(ListNode *head)
    {
        vector<int> vec;
        ListNode *temp = head;
        while (temp)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin(), vec.end());
        ListNode *newHead = new ListNode(0);
        temp = newHead;
        for (int i = 0; i < vec.size(); i++)
        {
            ListNode *newNode = new ListNode(vec[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return newHead->next;
    }
};