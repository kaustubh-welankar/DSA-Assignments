#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>

void reverse(char* arr, int left, int right){
    while(left<right){
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int main(){
    char arr[100];
    scanf("%[^'\n']s", arr);
    //printf("%s\n", arr);
    int left = 0; 
    int right = strlen(arr) - 1;
    reverse(arr,0, right);
    //printf("%s", arr);
    int len = strlen(arr);
    left = 0;
    right = 0;
    while(left < len){
        while(arr[right] != ' ' && arr[right] != '\0'){
            right++;
        }
        reverse(arr,left, right - 1);
        right++;
        left = right;
        
    }
    printf("%s\n", arr);
}