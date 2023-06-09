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

//~ Approach-1 : Recursion

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

//~ Approach-2 : Queue
//* Do Level Order Traversal, while adding Nodes at each level to Queue, we have to add NULL Node so that whenever it is encountered, we can increment the value of variable and that level get counted.
//* In short Null is used to separate elements of each levels

int heightQueue(Node *root)
{
    int depth = 0;
    queue<Node *> q;

    q.push(root);
    //* Root is only element at that level
    q.push(NULL);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        //* We successfully processed each element at this level
        if (temp == NULL)
        {
            depth++;
        }

        //* We add both element to queue and does not add NULL
        if (temp != NULL)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        //! Notice that it's else if
        //* We only add NULL when we encounter NULL //Hypocrisy:)
        //* Basically we only add NULL when we done adding all children of current level's nodes after NULL
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    //& Return after processing each level
    return depth;
}

//~ Approach-3: Without NULL with Queue

int height(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int height = 0;

    while (!q.empty())
    {
        //* Instead adding NULL to separate element we first take size and process all that element with adding their children
        //* We already remembering size so we'll take out that size and add all it's children and after each iteration we increase height by one
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        height++;
    }
    return height;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    cout << "Maximum Height : " << endl;
    cout << heightRec(root) << endl;
    cout << height(root) << endl;
    cout << heightQueue(root) << endl;

    return 0;
}