#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node
{
public:
    Node *links[26] = {NULL};
    int endWith = 0;
    int cntPrefix = 0;

    bool containChar(char ch) { return (links[ch - 'a'] != NULL); }
    void putChar(char ch, Node *node) { links[ch - 'a'] = node; }
    Node *getChar(char ch) { return links[ch - 'a']; }
    void increaseEnd() { endWith++; }
    void increasePrefix() { cntPrefix++; }
    void decreaseEnd() { endWith--; }
    void decreasePrefix() { cntPrefix--; }
};
class Trie
{

    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containChar(ch))
            {
                node->putChar(ch, new Node());
            }
            node = node->getChar(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containChar(ch))
                return 0;
            node = node->getChar(ch);
        }
        return node->endWith;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containChar(ch))
                return 0;
            node = node->getChar(ch);
        }
        return node->cntPrefix;
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containChar(ch))
                return;
            node = node->getChar(ch);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};
