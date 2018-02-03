#include <stdio.h>
#include <string.h>

int main(){
    char num[100];
    scanf("%s", num);
    int len = strlen(num);
    
    //-----Converting string to array and check digit-----
    int checkDigit = num[len - 1] - '0';
    int arr[len - 1];
    for(int i = 0; i < len - 1; i++){ arr[i] = num[i] - '0'; }

    //------Doubling all evenly placed digits, from the right-----
    int s = 0;
    for(int i = len - 2; i >= 0; i -= 2){
        arr[i] = arr[i]*2;
        if(arr[i] >= 10){
            arr[i] = arr[i]/10 + arr[i]%10;
        }
    }    

    for(int i = 0; i <= len -2; i++){
        s += arr[i];
    }

    if((s+checkDigit)%10 == 0){
        printf("Valid\n");
    }
    else{ printf("Invalid"); }
    return 0;
}