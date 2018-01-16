#include <stdio.h>
#include <stdlib.h>

struct node{
    char c;
    int count;
    struct node* next;
};
typedef struct node node;

void insert(char a, node** n){
    if(*n == NULL){
        node *temp = (node*)malloc(sizeof(node));
        temp->c = a;
        temp->count = 1;
        *n = temp;
    }
    else{
        node *it = *n;
        while(it->next != NULL && it->c != a){
            it = it->next;
        }
        if(it->c == a){
            it->count = it->count + 1;
        }
        else{
            node *temp = (node*)malloc(sizeof(node));
            temp->c = a;
            temp->count = 1;
            it->next = temp;
        }
    }    
}

int main(){
    node *head = NULL;

    char inp[1000];
    scanf("%[^\n]s", inp);

    char* a = inp;
    while(*a != '\0'){
        insert(*a, &head);
        a++;
    }

    node *n = head;
    while(n != NULL){
        printf("%c %d\n", n->c, n->count);
        n = n->next;
    }
    return 0;
}