//& Question: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure.

//^ Solution:

//* It's simple problem if it's a BST but sadly it's not one.

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
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);  // Left subtree first
    cout << root->val << " ";  // Then root
    printInorder(root->right); // Then right subtree
}

//~ Approach:1 :-
//* With parent and inefficient
//* Make deeper node to same level as shallower node and start searching for their parents to be equal

int depth(Node *node)
{
    int depth = 0;
    while (node != NULL)
    {
        node = node->parent;
        depth++;
    }
    return depth;
}

//* Make deeper node to go up at level of shallower node
Node *goUpBy(Node *node, int delta)
{
    while (delta > 0 && node != NULL)
    {
        node = node->parent;
        delta--;
    }
    return node;
}

Node *commonAncestor(Node *p, Node *q)
{
    int delta = depth(p) - depth(q);
    Node *first = delta > 0 ? q : p;
    Node *second = delta > 0 ? p : q;
    second = goUpBy(second, abs(delta));
    //* Find common parent
    while (first != second && first != NULL && second != NULL)
    {
        first = first->parent;
        second = second->parent;
    }
    return first == NULL || second == NULL ? NULL : first;
}

//~ Approach:2 :-
//* With parent and efficient
//* take one of the node, and go to it's parent and search other subtree, if other node is there then voila it's our common ancestor, otherwise go to it's parent

bool covers(Node *root, Node *p)
{
    if (root == NULL)
    {
        return false;
    }
    if (root == p)
    {
        return true;
    }
    return covers(root->left, p) || covers(root->right, p);
}

Node *getSibling(Node *node)
{
    if (node == NULL || node->parent == NULL)
    {
        return NULL;
    }
    Node *par = node->parent;
    return par->left == node ? par->right : par->left;
}

Node *commonAncestor2(Node *root, Node *p, Node *q)
{
    //* Check if either node is not in tree or one covers the other
    if (!covers(root, p) || !covers(root, q))
    {
        return NULL;
    }
    else if (covers(p, q))
    {
        return p;
    }
    else if (covers(q, p))
    {
        return q;
    }
    //* Find q in sibling
    Node *sibling = getSibling(p);
    //* Store it's parent
    Node *par = p->parent;
    while (!covers(sibling, q))
    {
        sibling = getSibling(par);
        par = par->parent;
    }
    return par;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    //*        1
    //*       / \
    //*      2   3
    //*    /  \   
    //*   4    5
    //*       /
    //*      7

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->left->right->left->parent = root->left->right;
    cout << (commonAncestor2(root, root->left->left, root->left->right->left))->val << endl;
    return 0;
}