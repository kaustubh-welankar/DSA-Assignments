#include<stdio.h>
#include<stdlib.h>

int cmp1(const void* a, const void* b){
    int* aPtr = (int*) a;
    int* bPtr = (int*) b;
    return *aPtr - *bPtr;
}


int cmp2(const void* a, const void* b){
    int* aPtr = (int*) a;
    int* bPtr = (int*) b;
    return *bPtr - *aPtr;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr1[(n+1)/2];
    int arr2[ (n/2) ];
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            scanf("%d", &arr1[i/2]); 
        }
        else{
            scanf("%d", &arr2[i/2]);
        }
    }
    
    qsort(arr1, (n+1)/2, sizeof(int), cmp1);
    qsort(arr2, n/2, sizeof(int), cmp2);

    for(int i = 0; i < (n+1)/2; i++){
        printf("%d ", arr1[i]);
    }
    for(int i = 0; i < n/2; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}