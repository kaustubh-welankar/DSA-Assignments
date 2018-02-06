#include<stdio.h>
#include<stdlib.h>

int cmpFunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void demerge(int* arr, int left, int mid, int right){
    int temp1[mid-left+1];
    int temp2[right - mid];
    int temp1ptr = 0;
    int temp2ptr = 0;
    for(int i = 0; i < right - left + 1; i++){
        int ele = arr[left + i];
        if((i % 2) == 0){
            temp1[temp1ptr] = ele;
            temp1ptr++;
        }
        else{
            temp2[temp2ptr] = ele;
            temp2ptr++;
        }
    }

    for(int i = 0; i < mid - left  + 1; i++){
        arr[left + i] = temp1[i];
    }
    for(int i = 0; i < right - mid; i++){
        arr[mid + 1 + i] = temp2[i];
    }

}

void desort(int* arr, int left, int right){
    if (left == right){
        return ;
    }
    int mid = (left + right)/2;
    demerge(arr,left,mid,right);
    desort(arr,left,mid);
    desort(arr,mid + 1, right);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){ scanf("%d", &arr[i]); }
    qsort(arr,n,sizeof(int), cmpFunc);  
    desort(arr,0,sizeof(arr)/sizeof(int) - 1);
    for(int i = 0; i < n; i++){ printf("%d ", arr[i]); }

}