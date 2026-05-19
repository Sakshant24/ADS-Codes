//Trie Data Structure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
struct Node{
    struct Node *child[26];
    bool eow; //end of word 0 or 1
};
struct Node *root = NULL;
struct Node *createNode(){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    for(int i=0; i<26; i++){
        ptr->child[i] = NULL;
    }
    ptr->eow = false;
    return ptr;
}
void insert(char word[]){
    struct Node *ptr = root;
    for(int i=0; word[i]!='\0'; i++){
        int indx = word[i]-'a';   
        if(ptr->child[indx] == NULL){
            ptr->child[indx] = createNode();
        }
        ptr = ptr->child[indx];
    }
    ptr->eow = true;
}
void display(struct Node *q, int level){
    for(int i=0; i<26; i++){
        if(q->child[i] != NULL){
            for(int j=0; j<level; j++){
                printf("_");
            }
            printf("%c", i+'a');
            if(q->child[i]->eow){
                printf("*");
            }
            printf("\n");
            display(q->child[i], level+1);
        }
    }
}
int main(){
    root = createNode();
    insert("cat");
    insert("cow");
    insert("car");
    insert("card");
    display(root, 0);
    return 0;
}