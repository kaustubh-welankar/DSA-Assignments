#include<stdio.h>
#include<stdlib.h>
//#include<limits.h>
#define INT_MAX 100000000

void reverse(int* arr, int pos){
    int left = 0;
    int right = pos;
    while(left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        right--;
        left++;
    }
    return ;
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){ scanf("%d", &arr[i]); }
     
    for(int i = 0; i < n - 1; i++){
        int minElement = INT_MAX;
        int minPosition = -1;
        for(int j = i; j < n; j++){
            if(arr[j] < minElement){
                minElement = arr[j];
                minPosition = j;
            }
        }   

        reverse(arr, minPosition);
        reverse(arr,minPosition - i);
        reverse(arr,minPosition);
    }
    
    for(int i = 0; i < n; i++){ printf("%d ", arr[i]); }
    printf("\n");
    return 0; 
}