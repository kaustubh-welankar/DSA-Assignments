#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){ scanf("%d", arr + i); }

    for(int i = 0; i < n; i++){
        int replacePos = -1;
        for(int j = i; j < n; j++){
            if( arr[j]%2 == 0 ){
                replacePos = j;
                break;
            }
        }
        while(replacePos > i){
            swap(&arr[replacePos], &arr[replacePos - 1]);
            replacePos--;
        }
        printf("%d  : ", i);
        for(int i = 0; i < n; i++){ printf("%d ", arr[i]); }
        printf("\n");    
    }    

    for(int i = 0; i < n; i++){ printf("%d ", arr[i]); }
    printf("\n");
    return 0;
}