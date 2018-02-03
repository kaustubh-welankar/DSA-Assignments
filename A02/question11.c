#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int err1 = -1, err2 = -1;
    int arr[n];

    scanf("%d", &arr[0]);
    for(int i = 1; i < n; i++){
        scanf("%d", &arr[i]);
        if(err1 == -1){
                if(arr[i] < arr[i-1]){ err1 = i - 1; }
        }
        else{
            if(arr[i] < arr[i-1]){err2 = i;break;}
        }
    }

    printf("Exchanged indices: %d %d\n", err1,err2);

    return 0;
}