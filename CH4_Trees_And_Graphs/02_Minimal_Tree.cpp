//& Question: Given sorted array of non repeating integers, Make balanced binary search tree.

//^ Solution:

//* We can simply make middle element as root and do recursive for both halfs on left and right.

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
        cout << root->val << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

Node *createMinBST(vector<int> &v, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *node = new Node(v[mid]);
    //* Make half tree of left and half on second
    node->left = createMinBST(v, start, mid - 1);
    node->right = createMinBST(v, mid + 1, end);
    return node;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *root = createMinBST(v, 0, v.size() - 1);
    inorder(root);
    cout << root->right->val << endl; //* 6
    return 0;
}

//* If you don't want to use pointer to max_level, Declare as global variable