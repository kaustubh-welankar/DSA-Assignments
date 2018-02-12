#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct data{
    int val;
    int count;
};
typedef struct data data;

int cmpFunc(const void* a, const void* b){
    data* aPtr = (data*)a;
    data* bPtr = (data*)b;
    return bPtr->count - aPtr->count;
    
}

int main(){
    int n;
    scanf("%d", &n);

    data arr[n];
    for(int i = 0; i < n; i++){
        arr[i].count = -1;
        arr[i].val = 0;
    }
    /*
    for(int i = 0; i < n; i++){
        printf("%d : %d \n", arr[i].val, arr[i].count);
    }
    */

    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        int pos = 0;
        while(arr[pos].val != temp && arr[pos].count != -1){
            pos++;
        }
        if(arr[pos].val == temp){
            arr[pos].count += 1;
        }
        else{
            arr[pos].val = temp;
            arr[pos].count = 1;
        }
    }

    qsort(arr,n,sizeof(data),cmpFunc);

    
    for(int i = 0; i < n; i++){
        if(arr[i].count == -1){ continue; }
        printf("%d : %d \n", arr[i].val, arr[i].count);
    }
    
    return 0;
}