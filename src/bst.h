#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct BSTNode {
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* bst_insert(BSTNode* root, int value);
bool bst_search(BSTNode* root, int value);

void bst_dfs_preorder(BSTNode* root);
void bst_dfs_inorder(BSTNode* root);
void bst_dfs_postorder(BSTNode* root);

void bst_bfs_level_order(BSTNode* root);

void bst_free(BSTNode* root);

#endif