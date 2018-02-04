#include <stdio.h>
#include <stdlib.h>
#define sizeArr(x) (sizeof(x)/sizeof(x[0]))

int merge(int* arr, int left, int mid, int right){
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    int inverts = 0;
    int leftPtr = 0;
    int rightPtr = 0;
    int output[right - left + 1];
    int outputPtr = 0;

    while(leftPtr < leftLength && rightPtr < rightLength){
        if(arr[left+leftPtr] <= arr[mid + 1 + rightPtr] ){
            output[outputPtr] = arr[left + leftPtr];
            leftPtr++;
        }else{
            output[outputPtr] = arr[mid + 1 + rightPtr];
            inverts += leftLength - leftPtr;
            rightPtr++;
        }
        outputPtr++;
    }

    if(leftPtr == leftLength){
        while(rightPtr < rightLength){
            output[outputPtr] = arr[mid + 1 + rightPtr];
            outputPtr++;
            rightPtr++;
        }
    }
    else{
        while(leftPtr < leftLength){
            output[outputPtr] = arr[left + leftPtr];
            leftPtr++;
            outputPtr++;
        }
    }
    for(int i = 0; i < right - left + 1; i++){
        arr[left + i] = output[i];
    }
    return inverts;
}

int modMergeSort(int* arr, int left, int right){
    if(left == right){
        return 0;
    }
    int mid = (left + right) / 2;
    int leftInverts  = modMergeSort(arr, left, mid);
    int rightInverts = modMergeSort(arr, mid + 1, right);
    int mergeInverts = merge(arr,left,mid,right);

    return leftInverts + rightInverts + mergeInverts;
}

int main(){
    int arr[] = {1,9,5,13,3,11,7,15,2,10,6,14,4,12,8,16};
    int inverts = modMergeSort(arr,0, sizeArr(arr) - 1);
    printf("Inverts are : %d\n", inverts);
    return 0;
}