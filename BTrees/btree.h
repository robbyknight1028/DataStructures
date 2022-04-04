#pragma once
#include "btreenode.h"

class BTree
{
    BTreeNode *root;  
    int t;  
public:
    // Constructor 
    BTree(int _t)
    {
        root = NULL;  t = _t;
    }

    
    
    void search();

    

    
    void insert(int k);
};