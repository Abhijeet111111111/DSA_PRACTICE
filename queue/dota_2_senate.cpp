#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {

        queue<int> index;
        queue<int> r;
        queue<int> d;

        for (int i = 0; i < senate.size(); i++)
        {
            index.push(i);
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (r.size() && d.size())
        {
            int idf = index.front();
            int rf = r.front();
            int df = d.front();
            if (senate[idf] == 'R')
            {
                d.pop();
                senate[df] = 'X';
                index.pop();
                index.push(idf);
                r.pop();
                r.push(rf);
            }
            else if (senate[idf] == 'D')
            {
                r.pop();
                senate[rf] = 'X';
                index.pop();
                index.push(idf);
                d.pop();
                d.push(df);
            }
            else
            {
                index.pop();
            }
        }

        if (r.size())
            return "Radiant";
        return "Dire";
    }
};