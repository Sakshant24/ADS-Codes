// Ass 7
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
    ptr->eow = 0;
    return ptr;
}
void suffix(char word[]){
    struct Node *ptr = root;
    for(int i=0; word[i] != '\0'; i++){
        int index = word[i] - 'a';
        if(ptr->child[index] == NULL){
            ptr->child[index] = createNode();
        }
        ptr = ptr->child[index];
    }
    ptr->eow = 1;
}
int insert(char word[]){
    int n = strlen(word);
    for(int i=0; i<n; i++){
        suffix(word + i);
    }
    return n;
}
void display(struct Node *q,int level,int indx,int l){
    for(int i=0; i<26; i++){
        if(q->child[i]!=NULL){
            for(int j=0; j<level; j++){
                printf("_");
            }
            printf("%c",i+'a');
            if(q->child[i]->eow){
                // printf("%d", i);
                printf("%d",l-indx-1);
            }   
            printf("\n");
            display(q->child[i],level+1,indx+1,l);
        }
    }
}
int main(){
    root = createNode();
    // int indx = 0;
    int l = insert("banana");
    display(root,0,0,l);
    return 0;
}