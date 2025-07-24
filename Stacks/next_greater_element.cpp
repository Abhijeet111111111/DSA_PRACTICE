#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n, -1);
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() && st.top() < arr[i])
            st.pop();
        if (st.size())
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }
}
