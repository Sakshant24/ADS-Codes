//min heap
// #include<stdio.h>
// #define MAX 100
// int heap[MAX];
// int size = 0;
// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void insert(int value){
//     if(size==MAX){
//         printf("Heap is full\n");
//         return;
//     }
//     heap[size] = value;
//     int index = size;
//     size++;
//     while(index>0){
//         int parent = (index-1)/2;
//         if(heap[index]<heap[parent]){
//             swap(&heap[index], &heap[parent]);
//                 index = parent;
//         }
//         else{
//             break;
//         }
//     }
// }
// void compare(int k){
//     int leftch = 2*k+1;
//     int rightch = 2*k+2;
//     int smallest = k;
//     if(leftch<size && heap[leftch]<heap[smallest]){
//         smallest = leftch;
//     }
//     if(rightch<size && heap[rightch]<heap[smallest]){
//         smallest = rightch;
//     }
//     if(smallest!=k){
//         swap(&heap[k], &heap[smallest]);
//         compare(smallest);
//     }
// }
// void deleteMin(){
//     if(size==0){
//         printf("Heap is Empty\n");
        //    return;
//     }
//     int delMin = heap[0];
//     heap[0] = heap[size-1];
//     size--;
//     compare(0);
// }
// void display(){
//     for(int i=0; i<size; i++){
//         printf("%d ", heap[i]);
//     }
//     printf("\n");
// }
// int main(){
//     insert(5);
//     insert(10);
//     insert(6);
//     insert(20);
//     insert(9);
//     insert(1);
//     printf("Heap Data:\n");
//     display();

//     deleteMin();
//     printf("Heap Data after deletion: \n");
//     display();
//     return 0;
// }

//max heap
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
    if(size==MAX){
        printf("Heap is full\n");
        return;
    }
    heap[size] = value;
    int index = size;
    size++;
    while(index>0){
        int parent = (index-1)/2;
        if(heap[index]>heap[parent]){
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}
void compare(int k){
    int leftch = 2*k+1;
    int rightch = 2*k+2;
    int largest = k;
    if(leftch<size && heap[leftch]>heap[largest]){
        largest = leftch;
    }
    if(rightch<size && heap[rightch]>heap[largest]){
        largest = rightch;
    }
    if(largest!=k){
        swap(&heap[k], &heap[largest]);
        compare(largest);
    }
}
void deleteMAX(){
    if(size==0){
        printf("Heap is empty\n");
        return;
    }
    int delMax = heap[0];
    heap[0] = heap[size-1];
    size--;
    compare(0);
}
void display(){
    for(int i=0; i<size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main(){
    insert(5);
    insert(10);
    insert(6);
    insert(20);
    insert(9);
    insert(21);
    insert(1);
    printf("Heap Data:\n");
    display();

    deleteMAX();
    printf("Heap Data after deletion: \n");
    display();
    return 0;
}