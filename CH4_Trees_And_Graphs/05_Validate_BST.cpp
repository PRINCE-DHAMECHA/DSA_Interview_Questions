//& Question: Check whether binary tree is BST or not.

//^ Solution:

//! Not that checking only left<=current<right will be not sufficient condition for BST, we need to check for all node of left subtree and right subtree to satisfy this.

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

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return new Node(key);
    }
    if (key < node->val)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->val)
    {
        node->right = insert(node->right, key);
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

//~ Approach-1 : Inorder (Without duplicates)
//* We can check inorder traverse to be sorted but instead keeping array for it we try to avoid making array

bool checkBST(Node *node, int &lastPrinted)
{

    if (node == NULL)
    {
        return true;
    }

    //* Check left
    //& Left
    if (!checkBST(node->left, lastPrinted))
    {
        return false;
    }

    //* If current node does not satisfy, return false
    if (lastPrinted != INT_MIN && node->val <= lastPrinted)
    {
        return false;
    }

    //& Root
    lastPrinted = node->val;

    //& Right
    if (!checkBST(node->right, lastPrinted))
    {
        return false;
    }
    //* Don't need to compare for right as we already checking in left.
    return true;
}

//~ Approach-2 : Min/Max
//* Start with (INT_MIN,INT_MAX) as (min,max) and for left node this will be (min,root->val) and for right node this will be (root->val,max)

bool effCheckBST(Node *node, int mini = INT_MIN, int maxi = INT_MAX)
{
    if (node == NULL)
    {
        return true;
    }
    if (node->val <= mini || node->val > maxi)
    {
        return false;
    }
    return effCheckBST(node->left, mini, node->val) && effCheckBST(node->right, node->val, maxi);
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
    insert(root, 60); /*//*/
    insert(root, 80);
    // * Check for invalid
    // root->left->left = new Node(60);
    int lastPrinted = INT_MIN;
    cout << checkBST(root, lastPrinted) << " " << effCheckBST(root) << endl;
    return 0;
}