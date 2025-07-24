#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flat(Node *head)
    {
        if (!head->next && !head->child)
            return head;
        Node *head_next = NULL;
        if (head->child)
        {
            head_next = head->next;
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;
        }
        Node *last_node = flat(head->next);
        if (head_next)
        {
            last_node->next = head_next;
            head_next->prev = last_node;
            last_node = flat(head_next);
        }
        return last_node;
    }
    Node *flatten(Node *head)
    {
        if (!head)
            return NULL;
        Node *temp = head;
        flat(temp);
        return head;
    }
};
