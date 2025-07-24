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
    Node* flatten(Node* head) {
        if(!head) return NULL;
        if(!head->next && !head->child) return head;
        Node* head_next = NULL;
        if(head->child) {
            head_next = head->next;
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;
        }
        Node* last_node = flatten(head->next);
        while(last_node->next) last_node = last_node->next;
        if(head_next) {
            last_node->next = head_next;
            head_next -> prev = last_node;
            last_node = flatten(head_next);
        }
        return head;
        
    }
};
