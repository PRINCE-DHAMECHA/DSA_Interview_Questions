//& Question: Implement all BT operation along with getRandomNode() which returns a random node from the tree.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :- Slow & Working
//* Take value of all node in array and return random element from the array
//* O(N)

//~ Approach:2 :- Slow & Working
//* We need to make BT from scratch so we maintain array while inserting and deleting
//* O(N)

//~ Approach:3 :- SLow & Working
//* Label node from 1 to N
//* generate random int from 1 to N and use BST
//* Same problem as above costly maintenance
//* O(N)

//~ Approach:4 :- Fast & !Working
//* What if we know depth?
//* We randomly select depth and randomly go left and right
//! All node is not equally likely to chosen

//~ Approach:5 :- Fast & !Working
//* we have three choices
//* 1/3 to return current
//* 1/3 to go right
//* 1/3 to go left
//! All node is not equally likely to chosen

//~ Approach:6 :- Fast & Working
//* Choosing root with probability 1/N
//* Choosing right with probability rightSideNodeCount * 1/N
//* Choosing left with probability leftSideNodeCount * 1/N
//* We're implementing BT from scratch remember size of right and left subtree at each node

class Node
{
public:
    int data;
    int size;
    Node *right;
    Node *left;
    Node(int d)
    {
        data = d;
        size = 1;
        right = NULL;
        left = NULL;
    }
    Node *getRandomNode()
    {
        int leftSize = left == NULL ? 0 : left->size;
        int randInt = (rand() % size) + 1;
        if (left == NULL && right == NULL)
        {
            return this;
        }
        if (randInt < leftSize)
        {
            return left->getRandomNode();
        }
        else if (randInt == leftSize)
        {
            return this;
        }
        else
        {
            return right->getRandomNode();
        }
    }
    void insertInOrder(int d)
    {
        if (d <= data)
        {
            if (left == NULL)
            {
                left = new Node(d);
            }
            else
            {
                left->insertInOrder(d);
            }
        }
        else
        {
            if (right == NULL)
            {
                right = new Node(d);
            }
            else
            {
                right->insertInOrder(d);
            }
        }
        size++;
    }
};

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

    Node *root = new Node(5);
    root->insertInOrder(1);
    root->insertInOrder(2);
    root->insertInOrder(3);
    root->insertInOrder(15);
    root->insertInOrder(10);
    cout << root->left->size << endl;
    cout << (root->getRandomNode())->data << endl;
    return 0;
}