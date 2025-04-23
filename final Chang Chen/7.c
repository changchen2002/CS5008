#include <stdio.h>

void insertMaxHeap(int heap[], int* size, int value) {
    int i;
    heap[*size] = value; 
    i = *size;
    (*size)++;
   
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
    
    