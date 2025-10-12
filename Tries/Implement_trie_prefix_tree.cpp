#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    char ch;
    unordered_map<char, Node *> children;
    bool isTerminal = false;
    Node(char ch)
    {
        this->ch = ch;
    }
    void makeTerminal()
    {
        this->isTerminal = true;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        this->root = new Node('\0');
    }

    void insert(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children.count(word[i]))
            {
                curr = curr->children[word[i]];
            }
            else
            {
                Node *child = new Node(word[i]);
                curr->children[word[i]] = child;
                curr = child;
            }
        }
        curr->makeTerminal();
    }

    bool search(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children.count(word[i]))
            {
                curr = curr->children[word[i]];
            }
            else
                return false;
        }
        if (curr->isTerminal)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (curr->children.count(prefix[i]))
            {
                curr = curr->children[prefix[i]];
            }
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */