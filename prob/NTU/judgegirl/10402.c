#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;
 
typedef struct Answer {
    int sumDepth;
    int sumData;
    int sumNum;
} Answer;
 
void trace(Node *root, Answer *ans) {
    if(root == NULL) return;
    Answer* lans = (Answer*)malloc(sizeof(Answer));
    Answer* rans = (Answer*)malloc(sizeof(Answer));
    lans->sumDepth = lans->sumData = 0, lans->sumNum = 0;
    rans->sumDepth = rans->sumData = 0, rans->sumNum = 0;
    trace(root -> left, lans);
    trace(root -> right, rans);
    ans -> sumData = lans -> sumData + rans -> sumData + root -> data;
    ans -> sumNum = lans -> sumNum + rans -> sumNum + 1;
    ans -> sumDepth = lans -> sumDepth + rans -> sumDepth + ans -> sumNum;
    free(lans);
    free(rans);
    return;
}

// #include "tree.h"
 
Node *newNode (int data, Node *l, Node *r) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = data;
    n->left = l;
    n->right = r;
    return n;
}
 
int main () {
    Node *root = newNode(
        10,
            newNode(
                5,
                    NULL,
                    newNode(2, NULL, NULL)               
            ),
            newNode(
                7,
                    newNode(1, NULL, NULL),
                    NULL            
            )
    );
    Answer *ans = (Answer*) malloc(sizeof(Answer));
    ans->sumDepth = 0;
    ans->sumData = 0;
    trace(root, ans);
    printf("%d %d\n", ans->sumDepth, ans->sumData);
    return 0;
}
