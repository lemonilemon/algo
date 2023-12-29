#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define INF (int)(1e9 + 7)
typedef struct Node {
    bool color;
    struct Node *left, *right;
    int farthestLeft, farthestRight;
} Node;
 
int max(int a, int b) {
    return a > b? a : b;
}
int maxDist(Node *root) {
    if(root == NULL) return 0;
    int ret = max(maxDist(root -> left), maxDist(root -> right));
    root->farthestLeft = -INF * root->color;
    root->farthestRight = -INF * root->color;
    if(root -> left != NULL) {
        root->farthestLeft = max(root->left->farthestLeft, root->left->farthestRight) + 1;
    }
    if(root -> right != NULL) {
        root->farthestRight = max(root->right->farthestLeft, root->right->farthestRight) + 1;
    }
    if(!root->color) ret = max(ret, max(root->farthestLeft, root->farthestRight));
    ret = max(ret, root->farthestLeft + root->farthestRight);
    return ret;
}

// #include "maxDist.h"
 
Node *newNode (bool color, Node *l, Node *r) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->color = color;
    n->left = l;
    n->right = r;
    n->farthestLeft = n->farthestRight = 0;
    return n;
}
 
int main () {
    Node *root = newNode(
        false, // 1
            newNode(
                true, // 2
                    newNode(
                        false, // 3
                            newNode(
                                true, // 4
                                    newNode(false,  NULL, NULL), // 5
                                    newNode(true,  NULL, NULL) // 6
                            ), 
                            newNode(
                                false, // 7
                                    newNode(true,  NULL, NULL), // 8
                                    NULL
                            )
                    ),
                    newNode(
                        false, // 9
                            newNode(
                                true, // 10
                                    NULL,
                                    newNode(false, NULL, NULL) // 11
                            ),
                            NULL
                    )    
            ),
            newNode(
                false, // 12
                    NULL,            
                    newNode(true, // 13
                                newNode(true, NULL, NULL), // 14
                                NULL)
            )
    );
    printf("%d\n", maxDist(root));
    return 0;
}
