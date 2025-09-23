#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> mp;
        int r = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == 0)
            {
                r++;
                continue;
            }
            mp[answers[i] + 1]++;
            if (mp[answers[i] + 1] == answers[i] + 1)
            {
                mp[answers[i] + 1] = 0;
                continue;
            }
            if (mp[answers[i] + 1] == 1)
                r += (answers[i] + 1);
        }
        return r;
    }
};