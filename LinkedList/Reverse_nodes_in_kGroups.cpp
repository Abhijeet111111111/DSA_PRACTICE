#include <iostream>
#include <math.h>
#include <vector>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        if (!head->next)
            return head;
        ListNode *temp = head;
        int size = 0;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        vector<pair<ListNode *, ListNode *>> v;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int x = ceil(size / k);
        while (x--)
        {
            int y = k;
            pair<ListNode *, ListNode *> mp = {curr, NULL};
            while (curr && y)
            {
                ListNode *Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next;
                y--;
            }
            mp.second = prev;
            v.push_back(mp);
            prev = NULL;
        }
        v.push_back({NULL, curr});
        for (int i = 0; i < v.size() - 1; i++)
        {
            auto currPair = v[i];
            auto nextPair = v[i + 1];
            currPair.first->next = nextPair.second;
        }
        return v[0].second;
    }
};