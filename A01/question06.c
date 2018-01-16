#include <stdio.h>

int main(){
    long long int c, n, p;
    scanf("%lld %lld %lld", &c, &n, &p);

    long long int powC = c, out = 1;
    while(n > 0){
        if(n % 2 == 1){
            out = (out * (powC%p))%p;
        }
        powC *= powC;
        n /= 2;
    }
    printf("%lld\n", out);
}