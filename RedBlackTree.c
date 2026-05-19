#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int val;
    struct Node *parent;
    struct Node *left, *right;
    bool color;
}; //0 for black and 1 for red
struct Node *root=NULL;
struct Node *leftRotate(struct Node *x){
    struct Node *y=x->right;
    struct Node *t=y->left;
    y->left=x;
    x->right=t;
    return y;
}
struct Node *rightRotate(struct Node *y){
    struct Node *x=y->left;
    struct Node *t=x->right;
    x->right=y;
    y->left=t;
    return x;
}
struct Node *insert(struct Node *node, int val){
    if(node==NULL){
        struct Node *ptr = (struct Node*)(malloc(sizeof(struct Node)));
        ptr->val=val;
        ptr->parent=NULL;
        ptr->color=1;
        ptr->left=ptr->right=NULL;
        
        return ptr;
    }
    else if(node->val > val){
        node->left = insert(node->left, val);
        node->left->parent = node;
    }
    else{
        node->right = insert(node->right, val);
        node->right->parent = node;
    }
    return node;
}
void fixInsert(struct Node *node){
    while(node->parent && node->parent->color==1){
        struct Node *gp = node->parent->parent; //grandparent
        if(!gp) break;
        if(node->parent == gp->left){
            struct Node *uncle = gp->right;
            if(uncle && uncle->color == 1){
                node->parent->color = 0;
                uncle->color = 0;
                gp->color = 1;
                node = gp;
            }
            else{
                if(node == node->parent->right){
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = 0;
                gp->color = 1;
                rightRotate(gp);
            }
        }
        else{
            struct Node *uncle = gp->left;
            if(uncle && uncle->color == 1){
                node->parent->color = 0;
                uncle->color = 0;
                gp->color = 1;
                node = gp;
            }
            else{
                if(node == node->parent->left){
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = 0;
                gp->color = 1;
                leftRotate(gp);
            }
        }
    }
    root->color = 0;
}
struct Node *i(struct Node *node, int val){
    struct Node *newNode = insert(node, val);
    if(root == NULL)    root = newNode;
    fixInsert(newNode);
    return root;
}
void display(struct Node *root){
    if(root == NULL)    return;
    printf("%d ", root->val);
    display(root->left);
    display(root->right);
}
int main(){
    root = i(root, 10);
    root = i(root, 20);
    root = i(root, 5);
    display(root);
    return 0;
}