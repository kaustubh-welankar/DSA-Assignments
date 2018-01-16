#include<stdio.h>
#include<string.h>

int main(){
    char s[10000];
    scanf("%s", s);

    int len = strlen(s);
    int i = 0;
    while(i*i < len){ i++; }
    
    if(i*i == len){
        char a[i][i];
        char *p = s;
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                a[j][k] = *p;
                p++;
            }
        }

        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                if (!(a[j][k] == a[k][j] && a[i-1-j][i-1-k] == a[j][k] && a[j][k] == a[i-1-k][i-1-j]))
                    {printf("NO\n");return 0;}
            }
        }
        printf("YES");
    }
    else{
        printf("NO: Length not a perfect square\n");
    }

    return 0;
}