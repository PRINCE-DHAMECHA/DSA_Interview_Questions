//& Question: Check whether given tree is balanced or not. For this question, Balanced tree is defined as tree such that the heights of the two subtrees of any node never differ by more than one.

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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

//~ Approach-1 : Inefficient O(NlogN)

int heightRec(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lHeight = heightRec(node->left);
        int rHeight = heightRec(node->right);
        //* increasing count by one because we're adding current node in height
        //* choose maximum height subtree as per definition of height
        return (lHeight > rHeight ? lHeight : rHeight) + 1;
    }
}

bool isBalanaced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int heightDiff = abs(heightRec(root->left) - heightRec(root->right));
    if (heightDiff > 1)
    {
        return false;
    }
    //* Recursively check both the subtree
    //! We need to recursively check because even if at root tree is balanced then that's not guaranteed that it's both subtree will be balanced
    return isBalanaced(root->left) && isBalanaced(root->right);
}

//~ Approach-1 : Efficient O(N)

//* return height along if balanced else error

int checkHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = checkHeight(root->left);
    if (leftHeight == INT_MIN)
    {
        return INT_MIN;
    }
    int rightHeight = checkHeight(root->right);
    if (rightHeight == INT_MIN)
    {
        return INT_MIN;
    }
    if (abs(leftHeight - rightHeight) > 1)
    {
        return INT_MIN;
    }
    else
    {
        return max(leftHeight, rightHeight) + 1;
    }
}

bool effIsBalanced(Node *root)
{
    return checkHeight(root) != INT_MIN;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //* Diff will be 1 //* Balanced
    root->right->right->right = new Node(7);
    //* Add this and diff will be 2 //* unbalanced
    // root->right->right->right->left = new Node(7); /
    // root->left->right->right = new Node(6);
    cout << isBalanaced(root) << " " << effIsBalanced(root) << endl;
    return 0;
}

//* If you don't want to use pointer to max_level, Declare as global variable