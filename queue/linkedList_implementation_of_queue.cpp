#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int val;
    Node(int val)
    {
        this->next = NULL;
        this->val = val;
    }
};

class queue
{
public:
    Node *f;
    Node *b;
    int size;
    queue()
    {
        this->f = this->b = NULL;
        this->size = 0;
    }
    void push(int val)
    {
        if (size == 0)
        {
            this->f = this->b = new Node(val);
            size++;
            return;
        }
        else
            this->b->next = new Node(val);
        size++;
        this->b = this->b->next;
        return;
    }
    int front()
    {
        return this->f->val;
    }
    void pop()
    {
        this->f = this->f->next;
        return;
    }

    void display()
    {
        Node *temp = f;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    queue *qu = new queue();
    qu->push(10);
    qu->push(20);
    qu->push(30);
    qu->push(40);
    qu->push(50);
    qu->display();
    cout << endl;
    cout << qu->size << endl;
    cout << qu->front() << endl;
    qu->pop();
    cout << qu->front() << endl;
    qu->display();
}