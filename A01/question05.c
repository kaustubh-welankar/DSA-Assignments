#include <stdio.h>

#define A 10000000000
int main(){
    int n ;
    scanf("%d", &n) ;
    long long int out = 1, pow2 = 2 ;
    while(n > 0){
        if (n%2 == 1){
            out = (out * (pow2%A))%A ;
        }
        n /= 2;
        pow2 *= pow2;
    }

    printf("%lld\n", out);
    return 0;
}