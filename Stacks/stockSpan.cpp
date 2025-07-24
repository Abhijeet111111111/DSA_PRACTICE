#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    int n = arr.size();
    stack<int> st;
    vector<int> pgi(n, -1);
    st.push(0);
    for (int i = 1; i < arr.size(); i++)
    {
        while (st.size() && arr[st.top()] < arr[i])
            st.pop();
        if (st.size())
            pgi[i] = st.top();
        st.push(i);
    }

    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        if (pgi[i] != -1)
            ans[i] = i - pgi[i];
        cout << ans[i] << " ";
    }
}