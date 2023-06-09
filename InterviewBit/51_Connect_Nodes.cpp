//& Write a function to connect nodes at the same level of a binary tree.

//~ Input:
//     100
//    /   \ 
//   13   15

//~ Output:
//    100 -> NULL
//   /   \
//  13 -> 15 -> NULL

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
    Node *nextRight;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
        nextRight = NULL;
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

//~ Approach:
//* we map level to node which stores all node at particular level from eft to right

void connect(Node *p)
{
    map<int, vector<Node *>> mp;
    queue<pair<Node *, int>> q;
    queue<int> l;
    q.push({p, 0});
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        mp[temp.second].push_back(temp.first);
        if (temp.first->left != NULL)
        {
            q.push({temp.first->left, temp.second + 1});
        }
        if (temp.first->right != NULL)
        {
            q.push({temp.first->right, temp.second + 1});
        }
    }
    //* Now for each vector we connnect first with second and so on....
    for (auto i : mp)
    {
        vector<Node *> temp = i.second;
        for (int i = 0; i < temp.size() - 1; i++)
        {
            temp[i]->nextRight = temp[i + 1];
        }
        //* At last we set NULL to nextRIght of last node
        temp[temp.size() - 1]->nextRight = NULL;
    }
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
    connect(root);
    cout << root->left->left->nextRight->nextRight->nextRight->val << endl;
    return 0;
}