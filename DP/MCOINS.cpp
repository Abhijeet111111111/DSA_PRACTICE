#include <iostream>
#include <vector>
using namespace std;
vector<int> v(1000001, 0);
void f(int k, int l)
{
    v[1] = 1;
    v[k] = 1;
    v[l] = 1;
    for (int i = 2; i < 1000001; i++)
    {
        v[i] = !(v[i - 1] and ((i - k) < 0 ? 1 : v[i - k]) and ((i - l) < 0 ? 1 : v[i - l]));
    }
}

int main()
{

    int k, l, n;
    cin >> k >> l;
    f(k, l);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (v[x])
        {
            cout << "A";
        }
        else
            cout << "B";
    }
}