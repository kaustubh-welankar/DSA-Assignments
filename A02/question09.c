//----Find a better approach than this----

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int numDigits = 0;
    int count = 0;
    for(int t = n; t > 0; t /= 10){ numDigits++;}
    int i, val;
    for(i = 1, val = 3; i < numDigits; i++, val *= 3){
        count += val;
    }
    
    for(int j = 0; j < val; j++){
        int gen = 0;
        int temp = j;
        for(int k = 0; k < i; k++, temp /= 3){
            gen *= 10;
            if(temp %3 == 0){
                gen += 1;
            }
            else if(temp %3 == 1){
                gen += 7;
            }
            else {
                gen += 9;
            }
        }
        int genRev = 0;
        while(gen > 0){
            genRev *= 10;
            genRev += gen % 10;
            gen /= 10;
        }
        if(genRev <= n){ printf("%d\n", genRev);count++; }
        else{ break; }
    }

    printf("%d\n", count);
    return 0;
}