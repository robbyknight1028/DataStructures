#include "btreenode.h"


BTreeNode::BTreeNode(int tree, bool leaf2)
{
   
    t = tree;
    leaf = leaf2;
    keys = new int[2 * t - 1];
    Children = new BTreeNode * [2 * t]; 
    n = 0;
}


void BTreeNode::search()
{
    int keyreturn[400];
    // Find the first key greater than or equal to k 
    int i = 0;
    while (i < n && keys[i] < n*2) {
        if (keys[i] > n) {
            keyreturn[i] = keys[i];
        }
    }

}

 
void BTreeNode::splitChild(int i, BTreeNode* y)
{

    //This is the the example code we were given. It is copied in to try to understand it better.
    //it is not used though I kept it here for full transparency
    /*BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}
