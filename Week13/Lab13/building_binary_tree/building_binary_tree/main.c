//
//  main.c
//  building_binary_tree
//
//  Created by Khongmeng Kormoua on 2020. 12. 03..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
 
typedef struct BTree {
    int value;
    struct BTree *left, *right;
} BTree;
 
BTree* insert(BTree*, int);
void print_inorder(BTree*);
void delete(BTree*);
int node(BTree*);
int sum(BTree*);
BTree* find(BTree*, int);
void negate(BTree*);

int main(void) {
    int sample[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BTree *root = NULL;
    int i;
    for (i = 0; sample[i] > 0; i++)
        root = insert(root, sample[i]);
 
    /* Call your functions here! */
    print_inorder(root);
    printf("\nThe tree has %d nodes.\n", node(root));
    printf("The sum value of the whole tree is: %d\n", sum(root));
    
    int lookAt = 21;
    printf("%d is at the address %p\n", lookAt, find(root, lookAt));
    
    negate(root);
    print_inorder(root);
    
    lookAt = -21;
    printf("\n%d is at the address %p\n\n", lookAt, find(root, lookAt));
    
    delete(root);
    return 0;
}

BTree *insert(BTree *root, int value) {
    if (root == NULL) {
        BTree *new_node = (BTree*) malloc(sizeof(BTree));
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (value < root->value) {        /* insert left */
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {   /* insert right */
        root->right = insert(root->right, value);
    }
    else {
        /* already in the tree */
    }
    return root;
}
void print_inorder(BTree* root) {
    if (root == NULL) return;
    print_inorder(root->left);
    printf("%d ", root->value);
    print_inorder(root->right);
}
void delete(BTree* root) {
    if (root == NULL) return;
    delete(root->left);
    delete(root->right);
    free(root);
}
int node(BTree* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return 1 + node(root->left) + node(root->right);
//    I'm so pround of this algorithm ^-^
}
int sum(BTree* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->value;
    return root->value + sum(root->left) + sum(root->right);
}
BTree* find(BTree* root, int num) {
    if (root != NULL && num != root->value && root->value > 0) {
        if (num > root->value) return find(root->right, num);
        else return find(root->left, num);
    }
    else if (root != NULL && num != root->value && root->value < 0){
        if (num > root->value) return find(root->left, num);
        else return find(root->right, num);
    }
    return root;
}
void negate(BTree* root) {
    if (root == NULL) return;
    negate(root->left);
    negate(root->right);
    root->value = root->value * (-1);
}
