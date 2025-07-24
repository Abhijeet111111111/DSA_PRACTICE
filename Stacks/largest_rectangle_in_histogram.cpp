#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nsi(n, n);
        stack<int> st;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.size())
                nsi[i] = st.top();
            st.push(i);
        }
        while (st.size())
            st.pop();
        st.push(0);
        vector<int> psi(n, -1);
        for (int i = 1; i < n; i++)
        {
            while (st.size() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.size())
                psi[i] = st.top();
            st.push(i);
        }
        int area = -999;
        for (int i = 0; i < n; i++)
        {

            area = max(area, (nsi[i] - psi[i] - 1) * heights[i]);
        }
        return area;
    }
};