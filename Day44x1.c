#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* buildTree(int arr[],int n){
    if(n==0) return NULL;

    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;

            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    return nodes[0];
}

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}