#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n){
    if(n == 0) return NULL;

    struct TreeNode* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i] != NULL){
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

void inorder(struct TreeNode* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct TreeNode* root = buildTree(arr,n);

    inorder(root);

    return 0;
}