// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    Node *links[26] = {NULL};
    bool flag = false;

    bool containsChar(char ch) { return (links[ch - 'a'] != NULL); }

    void putChar(char ch, Node *node) { links[ch - 'a'] = node; }

    Node *getChar(char ch) { return links[ch - 'a']; }

    void setEnd()
    {
        flag = true; // because flag of terminal node is true
    }

    bool isEnd() { return flag; }
    ~Node()
    {
        for (int i = 0; i < 26; i++)
        {
            if (links[i] != nullptr)
            {
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};
class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }

    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsChar(ch))
            {
                node->putChar(ch, new Node());
            }
            node = node->getChar(ch);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsChar(ch))
            {
                return false;
            }
            node = node->getChar(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (char ch : prefix)
        {
            if (!node->containsChar(ch))
            {
                return false;
            }
            node = node->getChar(ch);
        }
        return true;
    }
};
int main()
{
    Trie *t = new Trie();
    t->insert("abcd");

    cout << "Present or not: " << t->search("abcd") << endl;

    delete t;
    
    return 0;
}
