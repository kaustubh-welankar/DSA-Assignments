#include <stdio.h>
#include <stdlib.h>

struct d{
    int num;
    int numDivisors;
};
typedef struct d d;

int numDivisorsOf(int n){
    int c = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            c++;
        }
    }
    return c;
}
void merge(d* arr, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    d tempArr[right - left + 1];
    int tempPtr = 0;

    int leftPtr = 0;
    int rightPtr = 0;
    while(leftPtr < leftSize && rightPtr < rightSize){
        if(arr[left + leftPtr].numDivisors >= arr[mid + 1 + rightPtr].numDivisors){
            tempArr[tempPtr] = arr[left + leftPtr];
            leftPtr++;
            tempPtr++;
        }
        else{
            tempArr[tempPtr] = arr[mid + 1 + rightPtr];
            tempPtr++;
            rightPtr++;
        }
    }

    if(leftPtr == leftSize){
        while(rightPtr < rightSize){
            tempArr[tempPtr] = arr[mid + 1 + rightPtr];
            tempPtr++;
            rightPtr++;
        }
    }
    else{
        while(leftPtr < leftSize){
            tempArr[tempPtr] = arr[left + leftPtr];
            leftPtr++;
            tempPtr++;
        }
    }
    for(int i = 0; i < right - left + 1; i++){
        arr[left + i] = tempArr[i];
    }
}

void mergesort(d* arr, int left, int right){
    if(left == right){ return ; }

    int mid = (left+right)/2;
    
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    
    merge(arr,left,mid,right);
}

int main(){
    int n;
    scanf("%d", &n);
    d arr[n];
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        arr[i].num = temp;
        arr[i].numDivisors = numDivisorsOf(temp);
        printf("%d %d\n", arr[i].num, arr[i].numDivisors);
    }
    
    mergesort(arr,0,n-1);
    for(int i = 0; i < n; i++){ printf("%d ", arr[i].num); }
    printf("\n");
    return 0;
}