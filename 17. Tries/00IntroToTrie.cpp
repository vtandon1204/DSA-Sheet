// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    // void insertUtil(TrieNode *root, string word)
    // {
    //     // base case
    //     if (word.length() == 0)
    //     {
    //         root->isTerminal = true;
    //         return;
    //     }
    //     // assumption --> word in caps only
    //     char ch = toupper(word[0]);
    //     int index = ch - 'A';
    //     TrieNode *child;
    //     if (root->children[index] != NULL)
    //     { // present
    //         child = root->children[index];
    //     }
 queries.size()   //     else
    //     { // absent
    //         child = new TrieNode(ch);
    //         root->children[index] = child;
    //     }
    //     // recursion
    //     insertUtil(child, word.substr(1));
    // }
    // void insertWord(string word)
    // {
    //     insertUtil(root, word);
    // }

    // bool searchUtil(TrieNode *root, string word)
    // {
    //     // base case
    //     if (word.length() == 0)
    //     {
    //         return root->isTerminal;
    //     }
    //     char ch = toupper(word[0]);
    //     int index = ch - 'A';
    //     TrieNode *child;
    //     if (root->children[index] != NULL)
    //     {
    //         child = root->children[index];
    //     }
    //     else
    //     {
    //         return false;
    //     }
    //     return searchUtil(child, word.substr(1));
    // }
    // bool searchWord(string word)
    // {
    //     return searchUtil(root, word);
    // }
    void insertUtil(TrieNode *root, const string &word, int index)
    {
        // base case
        if (index == word.length())
        {
            root->isTerminal = true;
            return;
        }

        char ch = toupper(word[index]);
        int idx = ch - 'A';
        TrieNode *child;

        // present
        if (root->children[idx])
        {
            child = root->children[idx];
        }
        // absent
        else
        {
            child = new TrieNode(ch);
            root->children[idx] = child;
        }

        // recursion for the next character
        insertUtil(child, word, index + 1);
    }

    void insertWord(const string &word) { insertUtil(root, word, 0); }

    // Optimized searchUtil by using index instead of substr
    bool searchUtil(TrieNode *root, const string &word, int index)
    {
        // base case
        if (index == word.length())
        {
            return root->isTerminal;
        }

        char ch = toupper(word[index]);
        int idx = ch - 'A';

        TrieNode *child;
        // present
        if (root->children[idx])
        {
            child = root->children[idx];
        }
        // absent
        else
        {
            return false;
        }

        // recursion for the next character
        return searchUtil(child, word, index + 1);
    }

    bool searchWord(const string &word) { return searchUtil(root, word, 0); }

    // Optimized prefixUtil by using index instead of substr
    bool prefixUtil(TrieNode *root, const string &word, int index)
    {
        // base case
        if (index == word.length())
        {
            return true;
        }

        char ch = toupper(word[index]);
        int idx = ch - 'A';

        TrieNode *child;
        // present
        if (root->children[idx])
        {
            child = root->children[idx];
        }
        // absent
        else
        {
            return false;
        }

        // recursion for the next character
        return prefixUtil(child, word, index + 1);
    }

    bool startsWith(const string &prefix)
    {
        return prefixUtil(root, prefix, 0);
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertWord("abcd");

    cout << "Present or not: " << t->searchWord("ABCDE") << endl;
    return 0;
}
