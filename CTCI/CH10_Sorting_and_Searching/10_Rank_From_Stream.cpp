//& Question: Create a data structure which store element and it's cpunt and when you query getRank(i) it will give count of elements which is less than or equal to itself(not including itself).

//& Ex: 5,1,4,4,5,9,7,13,3
//& getRank(1)=0
//& getRank(4)=3

//^ Solution

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We can use BST with some additional properties
//* we store value along with count of all node with value less than current node in current node's count
//* So while searching for any key's rank we continuously add rank of each node if we traverse right next and don't add anything if we traversing left as we know in the right there's no element less than key

class RankNode
{
public:
    int val;
    int count;
    RankNode *left;
    RankNode *right;
    RankNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
        count = 0;
    }
    void insert(int d);
    int getRank(int d);
};

//* Inserting node in given BST
void RankNode::insert(int d)
{
    if (d <= val)
    {
        if (left != NULL)
        {
            left->insert(d);
        }
        else
        {
            left = new RankNode(d);
        }
        //* Increase count if we're indeed inserting in left side
        count++;
    }
    else
    {
        if (right != NULL)
        {
            right->insert(d);
        }
        else
        {
            right = new RankNode(d);
        }
    }
}

int RankNode::getRank(int d)
{
    if (d == val)
    {
        return count;
    }
    //* If traversing left
    else if (d < val)
    {
        //* When key doesn't exist return -1
        if (left == NULL)
        {
            return -1;
        }
        else
        {
            return left->getRank(d);
        }
    }
    //* While traversing right side return rightRank + leftRank + 1(node itself)
    else
    {
        int rightRank = right == NULL ? -1 : right->getRank(d);
        //* When key doesn't exist return -1
        if (rightRank == -1)
        {
            return -1;
        }
        else
        {
            //* all node less than this node + this node itself + rank of right node with given key
            return count + 1 + rightRank;
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    RankNode *root = new RankNode(5);
    root->insert(1);
    root->insert(4);
    root->insert(4);
    root->insert(5);
    root->insert(9);
    root->insert(7);
    root->insert(13);
    root->insert(3);
    cout << root->getRank(1) << endl;
    cout << root->getRank(3) << endl;
    cout << root->getRank(4) << endl;
    cout << root->getRank(10) << endl;
    return 0;
}