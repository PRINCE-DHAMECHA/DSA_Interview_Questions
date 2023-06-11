//& Question: Write an algorithm to find the "next" node(Inorder Successor) of given node in BST. You may assume that each node has a link to its parent.

//^ Solution:

//* Anyway what will be the inorder successor? :- Left most node of right subtree right?
//! But what if there's no right subtree?
//* We need to go upwards with nodes which is remaining to traverse and if we're at last node, then we return NULL!!

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
    Node(Node *p, int data)
    {
        val = data;
        left = NULL;
        right = NULL;
        parent = p;
    }
};

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return new Node(NULL, key);
    }
    if (key < node->val)
    {
        Node *lChild = insert(node->left, key);
        node->left = lChild;
        lChild->parent = node;
    }
    else if (key > node->val)
    {
        Node *rChild = insert(node->right, key);
        node->right = rChild;
        rChild->parent = node;
    }
    return node;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

Node *leftMostChild(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }
}

Node *inorderSucc(Node *n)
{
    if (n == NULL)
    {
        return NULL;
    }
    //* If there exists right subtree, return leftmost node of it
    if (n->right != NULL)
    {
        return leftMostChild(n->right);
    }
    else
    {
        Node *q = n;
        Node *x = q->parent;
        //* Go up until we're on left instead of right
        //* We'll find node which left side we're currently at i.e. x->left==q
        //* here q is parent
        while (x != NULL && x->left != q)
        {
            q = x;
            x = x->parent;
        }
        return x;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    cout << endl;
    cout << (inorderSucc(root->left->right))->val << endl;
    cout << (inorderSucc(root->left->left))->val << endl;
    cout << (inorderSucc(root->right->left))->val << endl;
    // cout << (inorderSucc(root->right->right))->val << endl; NULL
    return 0;
}