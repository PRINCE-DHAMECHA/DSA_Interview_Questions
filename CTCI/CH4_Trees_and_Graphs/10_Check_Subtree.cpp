//& Question: T1 and T2 are two very large BT, With T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.

//^ Solution:

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
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
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

//~ Approach:1 :- Compare preorder
//* It can be failed in below case
//*     3   3
//*    /     \
//*   2       2
//* Sol: Use NULL as node say X
//* Now order will be 3,2,X and 3,X,2

void getOrderString(Node *node, string &s)
{
    if (node == NULL)
    {
        s.append("X");
        return;
    }
    s.push_back(char((node->val) + '0'));
    getOrderString(node->left, s);
    getOrderString(node->right, s);
    return;
}

bool containsTree(Node *t1, Node *t2)
{
    string s1 = "";
    string s2 = "";
    getOrderString(t1, s1);
    getOrderString(t2, s2);
    cout << s1 << " - " << s2 << endl;
    if (s1.find(s2) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//~ Approach:2
//* Search entire T1 and whenever root matches search whole subtree
//* Pretty Much Self-Explanatory
bool matchTree(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    else if (r1 == NULL || r2 == NULL)
    {
        return false;
    }
    else if (r1->val != r2->val)
    {
        return false;
    }
    return matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right);
}

bool subTree(Node *t1, Node *t2)
{
    if (t1 == NULL)
    {
        return false;
    }
    else if (t1->val == t2->val && matchTree(t1, t2))
    {
        return true;
    }
    return subTree(t1->left, t2) || subTree(t1->right, t2);
}

bool containTree(Node *t1, Node *t2)
{
    if (t2 == NULL)
    {
        return true;
    }
    return subTree(t1, t2);
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
    Node *root1 = new Node(2);
    root1->left = new Node(4);
    root1->right = new Node(5);
    // root1->right->left = new Node(7);
    cout << containsTree(root, root->left) << endl;
    cout << containsTree(root, root1) << endl;
    cout << containTree(root, root->left) << endl;
    cout << containTree(root, root1) << endl;
    return 0;
}