#include <stdio.h>
#include <string.h>

int main(){
    char w[] = "goodbye";
    char c[100];
    scanf("%s", c);

    int wp = 0;
    int cp = 0;

    while(wp < strlen(w) && cp < strlen(c)){
        if(w[wp] == c[cp]){
            wp++;
        }
        cp++;
    }

    if(wp == strlen(w)){
        printf("Yes\n");
    }
    else{ printf("No\n"); }


}