#include<stdio.h>
#include<stdlib.h>
#define SPACE 10
struct Node{
    int data;
    int h;
    struct Node *left;
    struct Node *right;
};
struct Node* root = NULL;
int height(struct Node* node){
    if(node==NULL){
        return 0;
    }
    return node->h;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int balanceFactor(struct Node* node){
    if(node==NULL){
        return 0;
    }
    return height(node->left)-height(node->right);
}
struct Node* leftRotation(struct Node* x){
    struct Node *y = x->right;
    struct Node *t = y->left;
    y->left = x;
    x->right = t;
    x->h = 1+max(height(x->left),height(x->right));
    y->h = 1+max(height(y->left),height(y->right));
    return y;
}
struct Node* rightRotation(struct Node* y){
    struct Node *x= y->left;
    struct Node *t = x->right;
    x->right = y;
    y->left = t;
    x->h = 1+max(height(x->left),height(x->right));
    y->h = 1+max(height(y->left),height(y->right));
    return x;
}
struct Node* insert(struct Node* node,int data){
    if(node==NULL){
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->h = 1;
        ptr->left = ptr->right = NULL;
        return ptr;
    }
    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    else{
        return node;
    }
    node->h = 1+max(height(node->left),height(node->right));
    int bf = balanceFactor(node);
    //LL
    if(bf>1 && data<node->left->data){
        return rightRotation(node);
    }
    //RR
    if(bf<-1 && data>node->right->data){
        return leftRotation(node);
    }
    //LR
    if(bf>1 && data>node->left->data){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    //RL
    if(bf<-1 && data<node->right->data){
        node->right  = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}
void printTree(struct Node *root, int space){
    if(root==NULL){
        return;
    }
    space+=SPACE;
    printTree(root->right,space);
    for(int i=SPACE; i<space; i++){
        printf(" ");
    }
    printf("%d\n",root->data);
    printTree(root->left,space);   
}
int main(){
    int data;
    printf("Enter values(-1 to stop):\n");
    while(1){
        scanf("%d",&data);
        if(data==-1){
            break;
        }
        root = insert(root,data);
        printf("Current Height=%d\n",root->h);
    }
    printf("\nAVL Tree:\n");
    printTree(root,0);
    return 0;
}