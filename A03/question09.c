#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int customCmp(const void* a, const void* b){
    return(strcmp((char*)a, (char*)b));
}
int customPrint(char* c){
    int len = strlen(c);
    int i = 0;
    while(i < len){
        if(c[i] != '0'){ break; }
        i++;
    }
    while(i < len){
        printf("%c", c[i]);
        i++;
    }
    printf("\n");
}

int main(){
    int numStrings;
    scanf("%d", &numStrings);
    char inpArr[numStrings][1000];
    int maxLength = 0;
    for(int i = 0; i < numStrings; i++){
        scanf("%s", inpArr[i]);
        int len = strlen(inpArr[i]);
        if(len > maxLength){ maxLength = len;}
    }

    char sanitizedArr[numStrings][maxLength + 1];
    for(int i = 0; i < numStrings; i++){
        int len = strlen(inpArr[i]);
        int numZeros = maxLength - len;
        for(int j = 0; j < numZeros; j++){ sanitizedArr[i][j] = '0'; }
        for(int j = 0; j < len; j++){ sanitizedArr[i][numZeros + j] = inpArr[i][j]; }
        sanitizedArr[i][maxLength] = '\0';
    }

    qsort(sanitizedArr, numStrings, sizeof(char) * (maxLength+1), customCmp);
    printf("Sorted : \n");
    for(int i = 0; i < numStrings; i++){
        customPrint(sanitizedArr[i]);
        //printf("%s\n", sanitizedArr[i]);
    }

    return 0;
}