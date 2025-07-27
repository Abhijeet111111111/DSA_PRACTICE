#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> qu;
        stack<int> st;
        int n = students.size();
        for (int i = 0; i < n; i++)
        {
            qu.push(students[i]);
            st.push(sandwiches[n - i - 1]);
        }

        int count = 0;
        while (n && count != n)
        {
            int q_front = qu.front();
            int st_top = st.top();
            if (q_front == st_top)
            {
                qu.pop();
                st.pop();
                n--;
                count = 0;
            }
            else
            {
                count++;
                qu.push(qu.front());
                qu.pop();
            }
        }
        return n;
    }
};
