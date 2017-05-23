//
//  main.c
//  Selection Sort
//
//  Created by Anubhav Shrimal on 05/06/17.
//  Copyright © 2017 Anubhav Shrimal. All rights reserved.
//

#include <stdio.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], int size){
    int i, j;
    for(i = 0; i < size; i++){
        for (j = i+1; j < size; j++) {
            if(arr[i] > arr[j]){
                swap(arr, i, j);
            }
        }
    }
}

int main() {
    
    // input arr
    int arr[] = {3, 2, 1, 4, 5};
    int i;
    // find size of the array.
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Before selection sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // call selection sort function
    selection_sort(arr, n);
    
    printf("After selection sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
