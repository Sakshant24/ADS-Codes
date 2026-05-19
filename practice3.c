//Threaded Binary tree 
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *leftptr;
    struct Node *rightptr;
    int lthread;
    int rthread;
};
struct Node *root = NULL;
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->leftptr = newNode->rightptr = NULL;
    newNode->lthread = newNode->rthread = 1;
    return newNode;
}
void insert(int data){
    struct Node *ptr = root;
    struct Node *parent = NULL;
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
    struct Node *newNode = createNode(data);
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
struct Node* leftMost(struct Node *ptr){
    while(ptr!=NULL && ptr->lthread==0){
        ptr = ptr->leftptr;
    }
    return ptr;
}
void inorder(){
    struct Node* ptr = leftMost(root);
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        if(ptr->rthread==1){
            ptr = ptr->rightptr;
        }
        else{
            ptr = leftMost(ptr->rightptr);
        }
    }
}
int main(){
    insert(20);
    insert(30);
    insert(15);
    inorder();
    return 0;
}