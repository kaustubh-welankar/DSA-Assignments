#include <stdio.h>
#include <string.h>

int main(){
    char* thousands[] ={"", 
                        "One Thousand ",
                        "Two Thousand ",
                        "Three Thousand ",
                        "Four Thousand ",
                        "Five Thousand ",
                        "Six Thousand ",
                        "Seven Thousand ",
                        "Eight Thousand ",
                        "Nine Thousand "
                       };
    char* hundreds[] = {"",
                        "One Hundred ",
                        "Two Hundred ",
                        "Three Hundred ",
                        "Four Hundred ",
                        "Five Hundred ",
                        "Six Hundred ",
                        "Seven Hundred ",
                        "Eight Hundred ",
                        "Nine Hundred "
                       };
    char* teens[] =    {"Ten",
                        "Eleven",
                        "Twelve",
                        "Thirteen",
                        "Fourteen",
                        "Fifteen",
                        "Sixteen",
                        "Seventeen",
                        "Eighteen",
                        "Nineteen"
                       };

    char* tens[] =     {"",
                        "Ten ",
                        "Twenty ",
                        "Thirty ",
                        "Forty ",
                        "Fifty ",
                        "Sixty ",
                        "Seventy ",
                        "Eighty ",
                        "Ninety ",
                       };
    
    char* ones[] =     {"",
                        "One",
                        "Two",
                        "Three",
                        "Four",
                        "Five",
                        "Six",
                        "Seven",
                        "Eight",
                        "Nine"
                       };
    int n;
    scanf("%d", &n);
    int thousandsDigit = n/1000;
    int hundredsDigit = (n/100)%10;
    int tensDigit = (n%100)/10;
    int unitsDigit = n%10;
    
    printf("%s", thousands[thousandsDigit]);
    printf("%s", hundreds[hundredsDigit]);
    if(tensDigit == 1){
        printf("%s", teens[unitsDigit]);
    }
    else{
        printf("%s", tens[tensDigit]);
        printf("%s", ones[unitsDigit]);
    }
    printf("\n");
    return 0;
}