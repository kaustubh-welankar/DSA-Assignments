#include<stdio.h>

#define sizeofArr(x) (sizeof(x)/sizeof(x[0]))

void merge(int* arr, int left, int mid, int right){
    int a1[mid - left + 1];
    int a2[right - mid];
    int output[right - left + 1];

    for(int i = 0; i < mid - left + 1; i++){
        a1[i] = arr[left + i];
    }
    for(int i = 0; i < right - mid; i++){
        a2[i] = arr[mid + 1 + i];
    }

    int a1Ptr = 0, a2Ptr = 0, outPtr = 0;
    while(a1Ptr < mid - left + 1 && a2Ptr < right - mid){
        if(a1[a1Ptr] < a2[a2Ptr]){
            output[outPtr] = a1[a1Ptr];
            a1Ptr++;
        }else{
            output[outPtr] = a2[a2Ptr];
            a2Ptr++;
        }
        outPtr++;
    }

    if(a1Ptr == mid - left + 1){
        while(a2Ptr < right - mid){
            output[outPtr] = a2[a2Ptr];
            outPtr++;
            a2Ptr++;
        }
    }
    else{
        while(a1Ptr < mid - left + 1){
            output[outPtr] = a1[a1Ptr];
            outPtr++;
            a1Ptr++;
        }
    }
    for(int i = 0; i < right - left + 1; i++){
        arr[left + i] = output[i];
    }
}

void mergeSort(int* arr, int left, int right){
    if(left == right){ return; }
    int mid = (left + right) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}


int main(){
    int arr[] = {1,9,5,13,3,11,7,15,2,10,6,14,4,12,8,16};
    mergeSort(arr, 0, sizeofArr(arr) - 1);
    for(int i = 0; i < sizeofArr(arr); i++){printf("%d ", arr[i]);}
    printf("\n");

    return 0;
}