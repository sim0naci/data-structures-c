#include <stdio.h>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "bst.h"

int main(void) {
    printf("==== Linked List ====\n");
    LinkedList list;
    list_init(&list);
    list_push_back(&list, 10);
    list_push_back(&list, 20);
    list_push_front(&list, 5);
    list_print(&list);

    printf("Contains 20? %s\n", list_contains(&list, 20) ? "yes" : "no");
    list_remove_value(&list, 10);
    list_print(&list);
    list_clear(&list);

    printf("\n==== Stack ====\n");
    Stack s;
    stack_init(&s);
    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 3);

    int x;
    stack_pop(&s, &x);
    printf("Popped: %d\n", x);
    stack_peek(&s, &x);
    printf("Peek: %d\n", x);
    stack_free(&s);

    printf("\n==== Queue ====\n");
    Queue q;
    queue_init(&q);
    queue_enqueue(&q, 100);
    queue_enqueue(&q, 200);
    queue_enqueue(&q, 300);
    queue_dequeue(&q, &x);
    printf("Dequeued: %d\n", x);
    queue_peek(&q, &x);
    printf("Peek: %d\n", x);
    queue_free(&q);

    printf("\n==== BST (Tree) ====\n");
    BSTNode* root = NULL;
    int values[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        root = bst_insert(root, values[i]);
    }

    printf("Search 7? %s\n", bst_search(root, 7) ? "yes" : "no");
    printf("Search 2? %s\n", bst_search(root, 2) ? "yes" : "no");

    printf("DFS Preorder: ");
    bst_dfs_preorder(root);
    printf("\n");

    printf("DFS Inorder: ");
    bst_dfs_inorder(root);
    printf("\n");

    printf("DFS Postorder: ");
    bst_dfs_postorder(root);
    printf("\n");

    printf("BFS Level-order: ");
    bst_bfs_level_order(root);
    printf("\n");

    bst_free(root);

    printf("\nDone.\n");
    return 0;
}