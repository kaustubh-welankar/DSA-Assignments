#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    int* aPtr = (int*) a;
    int* bPtr = (int*) b;
    return *aPtr - *bPtr;
}

int binarySearch(int* arr, int left, int right, int key){
    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}


int main(){
    int n;
    int goal;
    scanf("%d %d", &n, &goal);
    int arr[n];
    for(int i = 0; i < n; i++){ scanf("%d", &arr[i]); }
    qsort(arr,n,sizeof(int),cmp);
    //for(int i = 0; i < n; i++){ printf("%d ",arr[i]); }
    for(int i = 0; i < n - 1; i++){
        int pos = binarySearch(arr, i + 1, n-1, goal - arr[i]);
        if(pos != -1){
            printf("%d + %d = %d\n", arr[i],arr[pos],goal);
            break;
        }
    }
}