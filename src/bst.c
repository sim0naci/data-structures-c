#include "bst.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static BSTNode* bst_create_node(int value) {
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    if (!n) return NULL;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

BSTNode* bst_insert(BSTNode* root, int value) {
    if (!root) return bst_create_node(value);

    if (value < root->value) {
        root->left = bst_insert(root->left, value);
    } else if (value > root->value) {
        root->right = bst_insert(root->right, value);
    }
    // se igual, não insere (evita duplicatas)
    return root;
}

bool bst_search(BSTNode* root, int value) {
    BSTNode* cur = root;
    while (cur) {
        if (value == cur->value) return true;
        if (value < cur->value) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}

void bst_dfs_preorder(BSTNode* root) {
    if (!root) return;
    printf("%d ", root->value);
    bst_dfs_preorder(root->left);
    bst_dfs_preorder(root->right);
}

void bst_dfs_inorder(BSTNode* root) {
    if (!root) return;
    bst_dfs_inorder(root->left);
    printf("%d ", root->value);
    bst_dfs_inorder(root->right);
}

void bst_dfs_postorder(BSTNode* root) {
    if (!root) return;
    bst_dfs_postorder(root->left);
    bst_dfs_postorder(root->right);
    printf("%d ", root->value);
}

// BFS por nível (level-order) usando Queue, mas a Queue é de int.
// Para guardar ponteiros em C "sem gambi", o certo seria uma Queue<void*>.
// Aqui vamos fazer uma fila simples de ponteiros dentro desta função.
typedef struct PtrQNode {
    BSTNode* ptr;
    struct PtrQNode* next;
} PtrQNode;

typedef struct PtrQueue {
    PtrQNode* head;
    PtrQNode* tail;
} PtrQueue;

static void ptrq_init(PtrQueue* q) { q->head = q->tail = NULL; }
static bool ptrq_push(PtrQueue* q, BSTNode* p) {
    PtrQNode* n = (PtrQNode*)malloc(sizeof(PtrQNode));
    if (!n) return false;
    n->ptr = p; n->next = NULL;
    if (!q->tail) q->head = q->tail = n;
    else { q->tail->next = n; q->tail = n; }
    return true;
}
static BSTNode* ptrq_pop(PtrQueue* q) {
    if (!q->head) return NULL;
    PtrQNode* n = q->head;
    BSTNode* p = n->ptr;
    q->head = n->next;
    if (!q->head) q->tail = NULL;
    free(n);
    return p;
}
static bool ptrq_empty(PtrQueue* q) { return q->head == NULL; }

void bst_bfs_level_order(BSTNode* root) {
    if (!root) return;
    PtrQueue q;
    ptrq_init(&q);

    ptrq_push(&q, root);
    while (!ptrq_empty(&q)) {
        BSTNode* cur = ptrq_pop(&q);
        printf("%d ", cur->value);
        if (cur->left) ptrq_push(&q, cur->left);
        if (cur->right) ptrq_push(&q, cur->right);
    }
}

void bst_free(BSTNode* root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}