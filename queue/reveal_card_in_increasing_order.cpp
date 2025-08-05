#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size(), -1);
        queue<int> q;
        for (int i = 0; i < deck.size(); i++)
        {
            q.push(i);
        }
        int i = 0;
        while (q.size())
        {
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
            i++;
        }
        return ans;
    }
};