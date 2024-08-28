#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Binary Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *node)
{
    int data;
    cout << "enter the data" << endl;
    cin >> data;
    Node *root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the right node of " << data << endl;
    root->right = buildTree(root->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void *buildTreeFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "enter the data for root node" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "enter the left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "enter the right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // creating tree
    // root = buildTree(root);

    // creating tree from level order traversal
    buildTreeFromLevelOrder(root);
    // Level Order Traversal
    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);

    // Inorder Traversal
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;
    // Preorder Traversal
    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    // Postorder Traversal
    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;
    return 0;
}