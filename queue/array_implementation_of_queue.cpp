#include <iostream>
using namespace std;
class queue
{
public:
    int arr[100];
    int f = 0, b = 0;
    queue()
    {
    }
    void push(int val)
    {
        this->arr[b] = val;
        this->b++;
    }
    void pop()
    {
        f++;
    }
    int front()
    {
        return arr[f];
    }
    int size()
    {
        return (b - f);
    }
    bool isEmpty()
    {
        if (size())
            return true;
        return false;
    }
    void display()
    {
        for (int i = 0; i < this->b; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    cout << "Array Implementation of queue!Aj!!!\n";
    queue *q = new queue();
    q->push(10);

    q->push(880);
    q->push(20);
    q->push(30);
    q->push(40);
    q->display();
}
