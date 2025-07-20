#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int val;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class doubly_ll
{
public:
    Node *head;
    Node *tail;
    Node *temp = head = tail;
    int size = 0;
    doubly_ll(int val)
    {
        head = new Node(val);
        tail = head;
        temp = head;
        size++;
    }

    void add(int val)
    {
        size++;
        Node *newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
        tail = temp;
    }

    void display()
    {
        Node *t = head;
        while (t)
        {
            cout << t->val << " ";
            t = t->next;
        }
        cout << "\n";
    }
    void display_rev()
    {
        Node *t = tail;
        while (t)
        {
            cout << t->val << " ";
            t = t->prev;
        }
        cout << "\n";
    }

    void insert_at_head(int val)
    {
        size++;
        Node *newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insert_at_tail(int val)
    {
        add(val);
    }

    void insert_at_idx(int val, int idx)
    {
        size++;
        if (idx == 0)
        {
            insert_at_head(val);
            return;
        }
        Node *t = head;
        while (idx > 1)
        {
            t = t->next;
            idx--;
        }
        Node *t_next = t->next;
        t->next = new Node(val);
        t->next->prev = t;
        t->next->next = t_next;
        t_next->prev = t->next;
    }
    void delete_at_head()
    {
        head = head->next;
        head->prev = NULL;
        size--;
    }
    void delete_at_tail()
    {
        tail = tail->prev;
        tail->next = NULL;
        size--;
    }
    void delete_at_idx(int idx)
    {
        Node *t = head;
        while (idx > 1)
        {
            t = t->next;
            idx--;
        }
        Node *t_next = t->next->next;
        t->next = t_next;
        t_next->prev = t;
        size--;
    }
    int get_at_head()
    {
        return head->val;
    }

    int void_get_at_idx(int idx)
    {
        if (idx >= size)
            return -1;
        Node *t = head;
        while (idx--)
        {
            t = t->next;
        }
        return t->val;
    }
    int get_at_tail()
    {
        return tail->val;
    }
};

int main()
{
    doubly_ll *dll = new doubly_ll(1);
    dll->add(2);
    dll->add(3);
    dll->add(4);
    dll->add(5);
    dll->add(6);
    dll->add(7);
    dll->insert_at_head(999);
    dll->insert_at_tail(88888);
    dll->insert_at_idx(10000, 3);
    dll->delete_at_head();
    dll->delete_at_tail();
    dll->delete_at_idx(2);
    dll->display();
    dll->display_rev();
    cout << dll->size << "\n";

    cout << dll->void_get_at_idx(9) << "\n";
}