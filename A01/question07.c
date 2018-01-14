#include<stdio.h>

int main(){
    long long int n;
    int count = 0;
    scanf("%lld", &n);
    while(n>0){
        count += n % 2;
        n /= 2;
    }

    printf("%d", count);
}