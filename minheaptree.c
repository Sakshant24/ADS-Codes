//Assignment 5 and ass6 is trie ds
#include<stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int value){
    if(size == MAX){
        printf("Heap is full\n");
        return;
    }
    heap[size] = value;
    int index = size;
    size++;
    //heapify 
    while(index > 0){
        int parent = (index-1)/2;
        if(heap[index] < heap[parent]){
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}
void compare(int k){
    int leftch = 2*k + 1;
    int rightch = 2*k + 2;
    int smallest = k;
    if(leftch < size && heap[leftch] < heap[smallest]){
        smallest = leftch;
    }
    if(rightch < size && heap[rightch] < heap[smallest]){
        smallest = rightch;
    }
    if(smallest!=k){
        swap(&heap[k], &heap[smallest]);
        compare(smallest);
    }
}
void deleteMin(){
    if(size==0){
        printf("Heap is Empty\n");
        return;
    }
    int delmin = heap[0];
    heap[0] = heap[size-1]; //replace first element(root) with last after deletion 
    size--;
    compare(0);
}
void display(){
    for(int i=0; i<size; i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
int main(){
    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(9);
    insert(11);
    insert(1);
    printf("Heap Data: \n");
    display();

    deleteMin();
    printf("Heap Data After Deletion: \n");
    display();
    return 0;
}






// #include<stdio.h>
// #define MAX 100
// int heap[MAX];
// int size=0;
// void swap(int *a, int*b){
//     int temp = *a;
//     *a=*b;
//     *b=temp;
// }
// void insert(int value){
//     heap[size] = value;
//     int index = size;
//     size++;
//     while(index > 0 && heap[index] < heap[(index-1) / 2] ){
//         swap(&heap[index], &heap[(index-1) / 2]);
//         index = (index-1)/2;
//     }
// }
// void deleteMin(int value){
//     int index=-1;
//     for(int i=0; i<size; i++){
//         if(heap[i]==value){
//             index=i;
//             break;
//         }
//         if(index==-1){
//             printf("value not found\n");
//             return;
//         }
//     }
//     heap[index]=heap[size-1];
//     size--;
//     while(1)
//     {
//         int leftch = 2*index+1;
//         int rightch = 2*index+2;
//         int smallest = index;
//         if(leftch<size && heap[smallest] > heap[leftch]){
//             smallest = leftch;
//         }
//         if(rightch<size && heap[smallest] > heap[rightch]){
//             smallest = rightch;
//         }
//         if(smallest!=index){
//             swap(&heap[index], &heap[smallest]);
//             index = smallest;
//         }
//         else{
//             break;
//         }

//     }
    
// }
// void display(){
//     for(int i=0; i<size; i++){
//         printf("%d ",heap[i]);
//     }
//     printf("\n");
// }
// int main(){
//     insert(10);
//     insert(20);
//     insert(5);
//     insert(6);
//     insert(9);
//     insert(11);
//     insert(1);
//     display();
//     deleteMin(1);
//     display();
//     return 0;
// }