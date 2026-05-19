#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *leftptr;
    struct node *rightptr;
    int lthread;
    int rthread;
};

struct node *root = NULL;

struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->leftptr = newNode->rightptr = NULL;
    newNode->lthread = newNode->rthread = 1;
    return newNode;
}
void insert(int data){
    struct node *ptr = root;
    struct node *parent = NULL;
    while(ptr!=NULL){
        if(data == ptr->data){
            printf("Duplicate not allowed\n");
            return;
        }
        parent = ptr;
        if(data < ptr->data){
            if(ptr->lthread == 0){
                ptr = ptr->leftptr;
            }
            else{
                break;
            }
        }
        else{
            if(ptr->rthread == 0){
                ptr = ptr->rightptr;
            }
            else{
                break;
            }
        }
    }
    struct node *newNode = createNode(data);
    if(parent == NULL){
        root = newNode;
        return;
    }
    if(data < parent->data){
        newNode->leftptr = parent->leftptr;
        newNode->rightptr = parent;
        parent->lthread = 0;
        parent->leftptr = newNode;
    }
    else{
        newNode->leftptr = parent;
        newNode->rightptr = parent->rightptr;
        parent->rthread = 0;
        parent->rightptr = newNode;
    }
}
struct node* leftMost(struct node *ptr){
    while(ptr!=NULL && ptr->lthread == 0){
        ptr = ptr->leftptr;
    }
    return ptr;
}
void inorder() {
    struct node *ptr = leftMost(root);

    while (ptr != NULL) {
        printf("%d ", ptr->data);

        if (ptr->rthread == 1)
            ptr = ptr->rightptr;
        else
            ptr = leftMost(ptr->rightptr);
    }
}
void preorder() {
    struct node *ptr = root;

    while (ptr != NULL) {
        printf("%d ", ptr->data);

        if (ptr->lthread == 0)
            ptr = ptr->leftptr;
        else if (ptr->rthread == 0)
            ptr = ptr->rightptr;
        else {
            while (ptr != NULL && ptr->rthread == 1)
                ptr = ptr->rightptr;
            if (ptr != NULL)
                ptr = ptr->rightptr;
        }
    }
}
int main() {
    int n, val, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        insert(val);
    }
    printf("\n1. Inorder Traversal");
    printf("\n2. Preorder Traversal");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Inorder: ");
        inorder();
    } else if (choice == 2) {
        printf("Preorder: ");
        preorder();
    }
    return 0;
}







// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// typedef struct Node
// {
//     /* data */
//     int data;
//     struct Node *left;
//     struct Node *right;
//     bool lthread,rthread;
// }Node;
// Node *root=NULL;
// Node *create(int val)
// {  Node *p=(Node *)malloc(sizeof(Node));
//     p->data=val;
//     p->left=NULL;
//     p->right=NULL;
//     p->lthread=true;
//     p->rthread=true;
//     return p;
// }
// void insert(int val)
// {
//     Node *p=create(val);
//     Node *parent=root;

//     if(root==NULL)
//     {
//         root=p;
//         return ;
//     }
   
//     else{
//         while(true)
//         {
//             if(parent->data > p->data)
//             { 
//                 if(parent->lthread)
//                 {
//                     p->left=parent->left;
//                     p->right=parent;
//                     parent->left=p;
//                     parent->lthread=0;
//                     return;
//                 }
//                 else{
//                     parent=parent->left;
//                 }

//             }
//             else{
//                 if(parent->rthread)
//                 {
//                     p->right=parent->right;
//                     p->left=parent;
//                     parent->right=p;
//                     parent->rthread=0;
//                     return ;
//                 }
//                 else{
//                     parent=parent->right;

//                 }
//             }
//         }

//     }

// }

// Node *leftmost(Node *n)
// {
//     if(n==NULL) return NULL;
//     while(!n->lthread)
//     {
//        n=n->left;
//     }
//     return n;
// }
// void inorder(Node *root)
// { if(root==NULL) return;
//     Node *curr=leftmost(root);
//     while(curr!=NULL)
//     { printf("%d->",curr->data);
//         if(curr->rthread) 
//         {
//             curr=curr->right;
//         }
//         else{
//             curr=leftmost(curr->right);
//         }
        
//     }

// }
// void preorder(Node *root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     Node *curr=root;
//     while(curr!=NULL)
//     {
//         printf("%d->",curr->data);
//         if(!curr->lthread)
//         {
//             curr=curr->left;
//         }
//        else if(!curr->rthread)
//         {
//             curr=curr->right;
//         }
//         // now you completed one left so we are following that so we have to at root so until curr.rthread will travel
//         // while loop ends so will reach 100 percent at root 
//         else{
//             while(curr!=NULL && curr->rthread)
//             {
//                 curr=curr->right;
//             }
//             if(curr!=NULL)
//             {
//                 curr=curr->right;
//             }
//         }

//     }
// }

 
// int main()
// {  insert(90);
//     insert(10);
//     insert(50);
//     insert(60);
   
//     // inorder(root);
//     printf("preorder\n");
//     preorder(root);
//     printf("inorder\n");
//     inorder(root);

// }