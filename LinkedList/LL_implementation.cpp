#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class LL
{
public:
    Node *head;
    Node *tail;
    int size = 0;
    LL(int val)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        this->size = 1;
    }
    int add(int val)
    {
        Node *newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    void add_at_head(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    void insert_at_index(int idx, int val)
    {
        if(idx >= size) return ;
        size++;
        if (idx == 0)
        {
            add_at_head(val);
            return;
        }
        Node *temp = head;
        int i = 0;
        while (i < idx - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *newNode = new Node(val);
        Node *temp_next = temp->next;
        temp->next = newNode;
        newNode->next = temp_next;
    }
    void delete_at_head(){
        head = head->next;
        size --;
    }
    void delete_at_idx(int idx)
    {
        if(idx == 0) delete_at_head();
        if(idx >= size) return;
        Node *temp = head;
        int i = 0;
        while (i < idx - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        size--;
    }
    int get_ele_at_idx(int i)
    {
        if (i == 0)
            return head->val;
        if (i == size - 1)
            return tail->val;
        if(i >= size) return -1;
        Node *temp = head;
        while(i){
            temp = temp->next;
            i --;
        }
        return temp->val;
    }
    void display()
    {
        Node *temp = head;
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
    LL *head = new LL(10);
    head->add(20);
    head->add(30);
    head->add(40);
    head->add(50);
    head->display();
    cout << "\n";
    cout << "size=>" << head->size << endl;
    head->add_at_head(90);
    head->display();
    cout << "size=>" << head->size << endl;
    head->insert_at_index(3, 99);
    head->display();
    cout << "size=>" << head->size << endl;
    head->delete_at_idx(3);
    head->display();
    cout << "size=>" << head->size << endl;
    cout<<head->get_ele_at_idx(5)<<"\n";
    head->delete_at_head();
    head->delete_at_head();
    head->display();
}