#include<stdio.h>
#include<stdlib.h>

void swap(int* arr, int pos1, int pos2, int* count){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
    *count += 1;
}

int bubbleSort(int* arr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){ swap(arr,j+1,j, &count);}
        }
    }
}

int selectionSort(int* arr, int n){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        int min = arr[i];
        int minPosition = i;
        for(int j = i; j < n; j++){
            if(min>arr[j]){
                min = arr[j];
                minPosition = j;
            }
        }
        swap(arr,i,minPosition,&count);
    }
    return count;
}

int insertionSort(int* arr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        int j = i - 1;
        while( j>=0 && arr[j] > arr[j + 1]){
                swap(arr, j, j + 1, &count);
        }
    }
    return count;
}
int main(){
    int numElements;
    scanf("%d", &numElements);

    int arrBubble[numElements];
    int arrSelection[numElements];
    int arrInsertion[numElements];

    for(int i = 0; i < numElements; i++){
        int temp;
        scanf("%d", &temp);
        arrBubble[i] = temp;
        arrSelection[i] = temp;
        arrInsertion[i] = temp;
    }

    //------Bubblesort driver code------
    int bubbleCount = bubbleSort(arrBubble, numElements);
    printf("Bubble Sort    : %d\n", bubbleCount);

    for(int i = 0; i < numElements; i++){
        printf("%d ", arrBubble[i]);
    }

    //------Selection Sort driver code------
    int selectionCount = selectionSort(arrSelection,numElements);
    printf("Selection Sort : %d\n", selectionCount);

    for(int i = 0; i < numElements; i++){
        printf("%d ", arrSelection[i]);
    }

    //------Insertion Sort driver code------
    int insertionCount = insertionSort(arrInsertion, numElements);
    printf("Insertion Sort : %d\n", insertionCount);
    
    for(int i = 0; i < numElements; i++){
        printf("%d ", arrInsertion[i]);
    }

    
    return 0;
}