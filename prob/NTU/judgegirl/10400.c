#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
struct treenode {
    uint64_t value;
    struct treenode *left;
    struct treenode *right;
};
 
typedef struct treenode TreeNode;
TreeNode *numToTree(uint64_t num, int bitNum) {
    if(num == 0 || bitNum == 0) return NULL;
    TreeNode* ret = malloc(sizeof(TreeNode));
    uint64_t lval = num >> (bitNum >> 1);
    uint64_t rval = num ^ (lval << (bitNum >> 1));
    ret->value = num;
    ret->left = numToTree(lval, bitNum >> 1);
    ret->right = numToTree(rval, bitNum >> 1);
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
// #include "numToTree.h"
#define NUMBITS 64
 
void preorderTree(TreeNode *root){
    if(root == NULL) return;
    printf("%llu ", root->value);
    preorderTree(root->left);
    preorderTree(root->right);
}
 
void inorderTree(TreeNode *root){
    if(root == NULL) return;
    inorderTree(root->left);
    printf("%llu ", root->value);
    inorderTree(root->right);
}
 
int main(){
    uint64_t num;
    scanf("%llu", &num);
 
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
    root = numToTree(num, NUMBITS);
 
    preorderTree(root);
    printf("\n");
    inorderTree(root);
    printf("\n");
 
    return 0;
}
