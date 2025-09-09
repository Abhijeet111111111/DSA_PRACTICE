#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        unordered_map<char, int> m;
        unordered_map<char, int> n;
        for (int i = 0; i < word1.size(); i++)
        {
            m[word1[i]]++;
            n[word2[i]]++;
        }
        for (auto ele : m)
        {
            if (n.find(ele.first) == n.end())
                return false;
        }
        unordered_map<int, int> p;
        unordered_map<int, int> q;
        for (auto ele : m)
        {
            p[ele.second]++;
        }
        for (auto ele : n)
        {
            q[ele.second]++;
        }
        for (auto ele : p)
        {
            if (q.find(ele.first) == q.end())
                return false;
            if (q.find(ele.first) != q.end())
            {
                if (ele.second != q[ele.first])
                    return false;
            }
        }
        return true;
    }
};