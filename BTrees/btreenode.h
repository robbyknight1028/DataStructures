#pragma once
#include <iostream>
#include "btree.h"


class BTreeNode
{
    int* keys;   
    int t;      
    BTreeNode** Children; 
    int n;     
    bool leaf; 
public:
    BTreeNode(int _t, bool _leaf);   // Constructor 

    
    
    void search(int k);   
    friend class BTree;
};

