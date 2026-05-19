#include<stdio.h>
#include<stdlib.h>
#define MAX 3   
struct Node{
    int key;
    struct Node *forward[MAX];
};
struct Node *header;
struct Node* createNode(int key){
    struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
    nn->key = key;
    for(int i=0;i<MAX;i++){
        nn->forward[i]=NULL;
    }
    return nn;
}
int randomLevel(){
    int level = 0;
    while(rand()%2==0 && level<MAX-1){
        level++;
    }
    return level;
}
void insert(int key){
    struct Node *update[MAX];
    struct Node *x = header;
    for(int i=MAX-1;i>=0;i--){
        while(x->forward[i] && x->forward[i]->key < key){
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];
    if(x == NULL || x->key != key){
        int lvl = randomLevel();
        struct Node *n = createNode(key);
        for(int i=0;i<=lvl;i++){
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
}
void display(){
    for(int i=MAX-1;i>=0;i--){
        struct Node *x = header->forward[i];
        printf("Level %d: ",i);
        while(x!=NULL){
            printf("%d ",x->key);
            x = x->forward[i];
        }
        printf("\n");
    }
}
int main(){
    // srand(time(0));
    header = createNode(-1); // header node
    insert(10);
    insert(20);
    insert(45);
    insert(30);

    display();
    return 0;
}