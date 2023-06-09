
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

//~ Right view of BST
//* We make variable which keeps track of levels and another variable for checking before printing that node

//! We are using pointer so that variable will be same for all recursion call
void rightViewUtil(Node *root, int level, int *max_level)
{
    if (root == NULL)
    {
        return;
    }
    if (*max_level < level)
    {
        cout << "\t" << root->val;
        //* increase max_level so that at that level other left side element will not
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

//* Wrapper over rightViewUtil
void rightView(Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

//~ Left view of BST
//* Same as Right one but we give priority to left child

void leftViewUtil(Node *root, int level, int *max_level)
{
    if (root == NULL)
    {
        return;
    }
    if (*max_level < level)
    {
        cout << "\t" << root->val;
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

//* Wrapper over leftViewUtil
void leftView(Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
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
    rightView(root);
    cout << endl;
    leftView(root);

    return 0;
}

//* If you don't want to use pointer to max_level, Declare as global variable