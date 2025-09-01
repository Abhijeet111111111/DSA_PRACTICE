#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        unordered_set<string> s;
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string curr = words[i];
            reverse(curr.begin(), curr.end());
            if (s.find(curr) != s.end())
            {
                count++;
            }
            else
                s.insert(words[i]);
        }
        return count;
    }
};