#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *duplicate = new Node(100);
        Node *td = duplicate;
        Node *th = head;
        while (th)
        {
            td->next = new Node(th->val);
            th = th->next;
            td = td->next;
        }
        duplicate = duplicate->next;
        td = duplicate;
        th = head;
        while (td)
        {
            Node *td_next = td->next;
            Node *th_next = th->next;
            th->next = td;
            td->next = th_next;
            td = td_next;
            th = th_next;
        }

        th = head;

        while (th)
        {
            if (th->next && th->random)
                th->next->random = th->random->next;
            // if(!th->next) break;
            th = th->next->next;
        }

        td = duplicate;
        th = head;

        while (th->next && td->next)
        {
            Node *th_next = th->next->next;
            Node *td_next = td->next->next;
            th->next = th_next;
            td->next = td_next;
            td = td_next;
            th = th_next;
        }
        if (th->next)
            th->next = NULL;
        return duplicate;
    }
};