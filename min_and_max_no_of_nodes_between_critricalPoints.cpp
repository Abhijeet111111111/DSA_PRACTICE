#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};
        ListNode *prev = head;
        ListNode *curr = head->next;
        int i = 1;
        vector<int> criticalPoints;
        while (curr->next)
        {
            ListNode *Next = curr->next;
            if (prev->val < curr->val && Next->val < curr->val)
                criticalPoints.push_back(i);
            else if (prev->val > curr->val && Next->val > curr->val)
                criticalPoints.push_back(i);
            prev = curr;
            curr = curr->next;
            i++;
        }
        int n = criticalPoints.size();
        if (n == 0 || n == 1)
            return {-1, -1};
        sort(criticalPoints.begin(), criticalPoints.end());
        int minDist = INT_MAX;
        for (i = 0; i < criticalPoints.size() - 1; i++)
        {
            minDist = min(minDist, criticalPoints[i + 1] - criticalPoints[i]);
        }
        int maxDist = criticalPoints[n - 1] - criticalPoints[0];
        return {minDist, maxDist};
    }
};