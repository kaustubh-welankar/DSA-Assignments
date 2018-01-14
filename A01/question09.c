//Matrix Multiplication

#include <stdio.h>
int main(){
    int y1,x1;
    scanf("%d %d", &y1, &x1);
    int mat1[x1][y1];
    for(int i = 0; i < y1; i++){
        for(int j = 0; j < x1; j++){
            scanf("%d", &mat1[j][i]);
        }
    }

    int y2,x2;
    scanf("%d %d", &y2, &x2);
    int mat2[x2][y2];
    for(int i = 0; i < y2; i++){
        for(int j = 0; j < x2; j++){
            scanf("%d", &mat2[j][i]);
        }
    }

    int out[x2][y1];
    for(int i = 0; i < y1; i++){
        for(int j = 0; j < x2; j++){
            int s = 0;
            for(int k = 0; k < x1; k++){
                s += mat1[k][i] * mat2[j][k];
            }
            out[j][i] = s;
        }
    }

    int sum = 0;
    for(int i = 0; i < y1; i++){
        for(int j = 0; j < x2; j++){
            sum += out[j][i];
        }
    }

    printf("%d", sum);
}