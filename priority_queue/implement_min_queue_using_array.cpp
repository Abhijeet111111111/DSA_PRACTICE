#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node(int val)
    {
        left = right = NULL;
        this->val = val;
    }
};

class minHeap
{
public:
    int arr[51];
    int idx;
    minHeap()
    {
        idx = 1;
    }

    void push(int val)
    {
        arr[idx] = val;
        int i = idx;
        idx++;
        while (i)
        {
            if (arr[i] < arr[i / 2])
            {
                swap(arr[i], arr[i / 2]);
                i /= 2;
            }
            else
                break;
        }
    }
    void display()
    {
        for (int i = 1; i < idx; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void pop()
    {
        swap(arr[idx - 1], arr[1]);
        int i = 1;
        idx--;
        while (true)
        {
            if (2 * i > idx - 1)
                break;

            if (2 * i + 1 > idx - 1)
            {
                if (arr[2 * i] < arr[i])
                    swap(arr[2 * i], arr[i]);
                break;
            }

            if (arr[2 * i] < arr[2 * i + 1]) // left < right
            {
                if (arr[i] > arr[2 * i])
                { // root->val > left;
                    swap(arr[i], arr[2 * i]);
                    i = 2 * i;
                }
                else
                    break;
            }
            else // right < left
            {
                if (arr[i] > arr[2 * i + 1])
                { // root->val > right;
                    swap(arr[i], arr[2 * i + 1]);
                    i = 2 * i + 1;
                }
                else
                    break;
            }
        }
    }

    int size() { return idx - 1; }
};

int main()
{
    minHeap pq;
    pq.push(1);
    pq.push(18);
    pq.push(12);
    pq.push(-1);
    pq.push(19);
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.push(2);
    pq.display();
    pq.push(-2);
    pq.display();
}