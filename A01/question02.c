//Problem : finding number of occurances of a word in a sentence

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    char word[100], sentence[10000];
    gets(word);
    gets(sentence);

    
    int len = strlen(word);
    int byteSize = len * sizeof(char);
    
    char *p = sentence;
    int count = 0;
    while (*(p + byteSize - 1) != '\0'){
     if(memcmp(word,p,byteSize) == 0){
         count++;
     }  
     p++; 
    }

    printf("%d", count);

}