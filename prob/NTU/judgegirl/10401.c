#include <stdio.h>
#include <stdlib.h>

#define MAXARR 10000
struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
typedef struct treenode TreeNode;
TreeNode *buildTree(int traverseOrder[MAXARR], int arrSize) {
    TreeNode* ret = malloc(sizeof(TreeNode)); 
    ret->value = traverseOrder[0];
    if(arrSize == 1) {
        ret->left = NULL;
        ret->right = NULL;
        return ret;
    }
    for(int i = 1; i < arrSize; ++i) {
        if(traverseOrder[i] == ret->value) {
            ret->left = buildTree(traverseOrder + 1, i);
            ret->right = buildTree(traverseOrder + i + 1, arrSize - i);
            break;
        }
    }
    return ret;
}



// #include "buildTree.h"
 
void preorderTree(TreeNode *root){
    if(root == NULL) return;
    printf("%d ", root->value);
    preorderTree(root->left);
    preorderTree(root->right);
}
 
void inorderTree(TreeNode *root){
    if(root == NULL) return;
    inorderTree(root->left);
    printf("%d ", root->value);
    inorderTree(root->right);
}
 
int main(){
    int traverseOrder[MAXARR];
    int arrSize = 0;
 
    while(scanf("%d", &traverseOrder[arrSize]) != EOF)
        arrSize++;
 
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    root = buildTree(traverseOrder, arrSize);
 
    preorderTree(root);
    printf("\n");
    inorderTree(root);
    printf("\n");
 
    return 0;
}
