//
//  main.c
//  Count number of leaf in n ary tree
//
//  Created by Anubhav Shrimal on 06/06/17.
//  Copyright © 2017 Anubhav Shrimal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode* treeptr;

struct treeNode{
    char data;
    treeptr leftMostChild, rightSibling;
};

int DoSomething(treeptr t){
    int value = 0;
    
    if(t != NULL){
        // if t is a leaf node set value = 1
        if(t->leftMostChild == NULL)
        {
            value = 1;
            printf("leaf %c\n", t->data);
        }
        else
            // else goto the leftMostChild of t recursively
            value = DoSomething(t->leftMostChild);
        
        // goto the rightSibling of each node to find if it is leaf recursively
        value = value + DoSomething(t->rightSibling);
    }
    return value;
}

// helper function to create the nodes in the tree
treeptr create(char ch){
    treeptr temp = (treeptr)malloc(sizeof(struct treeNode));
    temp->data = ch;
    temp->leftMostChild = NULL;
    temp->rightSibling = NULL;
    return temp;
}

int main() {
    treeptr root = create('a');
    root->leftMostChild = create('b');
    root->leftMostChild->rightSibling = create('c');
    root->leftMostChild->rightSibling->rightSibling = create('d');
    root->leftMostChild->rightSibling->rightSibling->rightSibling = create('e');
    root->leftMostChild->leftMostChild = create('f');
    root->leftMostChild->leftMostChild->rightSibling = create('g');
    root->leftMostChild->leftMostChild->rightSibling->rightSibling = create('h');
    
    /*
     Structure of n-ary tree:
        a
       /
       b->c->d->e
       /
       f->g->h
     
     Number of leaf nodes = 6
     
     */
    
    // call count leaves function DoSomething on the root
    int leafNodes = DoSomething(root);
    
    // print the number of leaves in the tree
    printf("Number of leaf nodes: %d\n", leafNodes);
    
    
    /*
     Output:-
     leaf f
     leaf g
     leaf h
     leaf c
     leaf d
     leaf e
     Number of leaf nodes: 6
     
     */
    return 0;
}
