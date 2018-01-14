//Problem: Finding factorial of numbers upto 200
//long long int can store only upto 20!

#include<stdio.h>

void print(int arr[], int s){
    int i = 0;
    while(i < s && arr[i] == 0){
        i++;
    }
    for(; i < s; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);

    //Upper bound for 200! : 10^400
    int fact[400];
    for(int i = 0; i < 400; i++){
        fact[i] = 0;
    }
    fact[399] = 1;

    for(int i = 1; i <= n; i++){
        int carry = 0;
        for(int j = 399; j >= 0; j--){
            fact[j] = fact[j] * i + carry;
            carry = fact[j] / 10;
            fact[j] = fact[j] % 10;
        }
    }

    print(fact, 400);
    return 0;
}