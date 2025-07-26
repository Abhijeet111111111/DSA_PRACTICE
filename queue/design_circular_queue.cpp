#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
public:
    int cap;
    int noe;
    int b, f;
    vector<int> v;
    MyCircularQueue(int k)
    {
        cap = k;
        noe = 0;
        b = 0;
        f = 0;
        v.resize(k, -1);
    }

    bool enQueue(int value)
    {
        if (noe == cap)
            return false;
        if (b == cap)
            b = 0;
        v[b] = value;
        noe++;
        b++;
        return true;
    }

    bool deQueue()
    {
        if (noe == 0)
            return false;
        if (f == cap)
            f = 0;
        f++;
        noe--;
        return true;
    }

    int Front()
    {
        if (noe == 0)
            return -1;
        if (f == cap)
            f = 0;
        return v[f];
    }

    int Rear()
    {
        if (noe == 0)
            return -1;
        return v[b - 1];
    }

    bool isEmpty()
    {
        if (noe == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (noe == cap)
            return true;
        return false;
    }
};