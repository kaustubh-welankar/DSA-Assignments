#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    char arr[n + 1];
    arr[n] = '\0';
    printf("The smallest number is: ");
    if(k == 1){
        for(int i = 0; i < n; i++){
            arr[i] = '1';
        }
    }
    else{
        arr[0] = 1 + '0';
        for(int i = 0 ; i < n - k + 1; i++){
            arr[1 + i] = '0';
        }
        for(int i = 0; i < k - 2; i++){
            arr[i+n-k+2] = i + 2 + '0';
        }
    }
    printf("%s\n", arr);


    printf("The largest number is: ");
    for(int i = 0; i < n + 1 - k; i++){
        arr[i] = '9';
    }
    
    for(int i = n + 1 - k, j = 8; i < n; i++, j--){
        arr[i] = j + '0';
    }

    printf("%s\n", arr);

}