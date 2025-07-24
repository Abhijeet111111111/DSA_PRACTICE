#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = arr.size();
    stack<int> st;
    vector<int> pge(n, -1);
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        while (st.size() && st.top() < arr[i])
            st.pop();
        if (st.size())
            pge[i] = st.top();
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pge[i] << " ";
    }
}