#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct t{
    int val;
    int weight;
};
typedef struct t weightedInt;

int isLeftLessThanOrEqual(weightedInt a, weightedInt b){
    if(a.weight < b.weight){
        return 1;
    }
    else if(a.weight == b.weight){
        if(a.val < b.val){return 1;}
        else{return 0;}
    }
    else{
        return 0;
    }
}

void merge(weightedInt* arr, int left, int mid, int right){
    int leftPtr = 0;
    int rightPtr = 0;
    int mergePtr = 0;
    weightedInt tempArr[right-left+1];
    while(leftPtr < mid - left + 1 && rightPtr < right - mid){
        if(isLeftLessThanOrEqual(arr[left+leftPtr],arr[mid+1+rightPtr])){
            tempArr[mergePtr] = arr[left+leftPtr];
            leftPtr++;
            mergePtr++;
        }
        else{
            tempArr[mergePtr] = arr[mid+1+rightPtr];
            rightPtr++;
            mergePtr++;
        }
    }
    if(leftPtr == mid - left + 1){
        while(rightPtr < right-mid){
            tempArr[mergePtr] = arr[mid+1+rightPtr];
            rightPtr++;
            mergePtr++;
        }
    }
    else{
        while(leftPtr < mid - left + 1){
            tempArr[mergePtr] = arr[left+leftPtr];
            leftPtr++;
            mergePtr++;
        }
    }
    for(int i = 0; i < right - left + 1; i++){
        arr[left + i] = tempArr[i];
    }
}

void mergeSort(weightedInt* arr, int left, int right){
    if(left == right){
        return ;
    }
    int mid = (left + right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    weightedInt X[x];
    int Y[y];

    for(int i = 0; i < x; i++){
        int t;
        scanf("%d", &t);
        X[i].val = t;
        X[i].weight = INT_MAX;
    }
    for(int i = 0; i < y; i++){scanf("%d", &Y[i]);}

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(Y[i] == X[j].val){X[j].weight = i;}
        }
    }

    mergeSort(X,0,x-1);
    for(int i = 0; i < x; i++){
        printf("%d ", X[i].val);
    }
    printf("\n");
    
    return 0;
}