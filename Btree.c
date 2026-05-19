//Assignment 4
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int k1;
    int k2;
    struct Node *leftch, *middlech, *rightch; 
    int c;
};
struct Node *root = NULL;
struct Node *newNode(int key){ //creating newNode
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->k1 = key;
    ptr->k2 = 0;
    ptr->c = 1;
    ptr->leftch = ptr->middlech = ptr->rightch = NULL;
    return ptr;
}
//Insert key into node that has space
void insertIntoNode(struct Node *ptr, int key, struct Node *child){
    if(key < ptr->k1){
        ptr->k2 = ptr->k1;
        ptr->k1 = key;
        ptr->rightch = ptr->middlech;
        ptr->middlech = child;
    }
    else{   
        ptr->k2 =key;
        ptr->rightch = child;
    }
    ptr->c = 2;
}
struct Node *split(struct Node *ptr, int key, struct Node *child, int *upkey){
    int a = ptr->k1;
    int b = ptr->k2;
    int c = key;
    //Sorting the three Keys
    if(a > b){ int t=a; a=b; b=t; }
    if(a > c){ int t=a; a=c; c=t; }
    if(b > c){ int t=b; b=c; c=t; }
    *upkey = b; //middle key goes up
    ptr->k1 = a; //left node keeps smallest
    ptr->c = 1;
    struct Node *newRight = newNode(c);
    if(child != NULL){
        newRight->leftch = ptr->rightch;
        newRight->middlech = child;
        ptr->rightch = NULL;
    }
    return newRight;
}
struct Node *insertRec(struct Node *ptr, int key, int *upkey, int *splitFlag){
    struct Node *newChild = NULL;
    //Leaf Node
    if(ptr->leftch == NULL){
        if(ptr->c==1){
            insertIntoNode(ptr, key, NULL);
            *splitFlag = 0;
            return NULL;
        }
        else{
            *splitFlag = 1;
            return split(ptr, key, NULL, upkey);
        }
    }
    //Internal Node
    if(key < ptr->k1){
        newChild = insertRec(ptr->leftch, key, upkey, splitFlag);
    }
    else if(ptr->c == 2 && key > ptr->k2){
        newChild = insertRec(ptr->rightch, key, upkey, splitFlag);
    }
    else{
        newChild = insertRec(ptr->middlech, key, upkey, splitFlag);
    }
    if(*splitFlag){
        if(ptr->c == 1){
            insertIntoNode(ptr, *upkey, newChild);
            *splitFlag = 0;
            return NULL;
        }
        else{
            return split(ptr, *upkey, newChild, upkey);
        }
    }
    return NULL;
}
//insert wrapper
void insert(int key){
    if(root == NULL){
        root = newNode(key);
        return;
    }
    int upkey;
    int splitFlag = 0;
    struct Node *newChild = insertRec(root, key, &upkey, &splitFlag);
    if(splitFlag){
        struct Node *newRoot = newNode(upkey);
        newRoot->leftch = root;
        newRoot->middlech = newChild;
        root = newRoot;
    }
}
void inorder(struct Node *ptr){
    if(ptr==NULL){
        return;
    }
    inorder(ptr->leftch);
    printf("%d ", ptr->k1);
    inorder(ptr->middlech);
    if(ptr->c==2){
        printf("%d ", ptr->k2);
        inorder(ptr->rightch);
    }
}
int main() {
    int keys[] = {10, 20, 30, 5, 35, 40};
    for (int i = 0; i < 6; i++){
        insert(keys[i]);
    }
    printf("Inorder Traversal:\n");
    inorder(root);
    return 0;
}