#include <stdio.h>
#include <malloc.h>

typedef struct arr {
    int val;
    struct arr* next;
} myArr;

myArr* Clone(myArr* list) {
    if (list == NULL) return NULL;

    myArr* result = malloc(sizeof(myArr));
    result->val = list->val;
    result->next = Clone(list->next);
    return result;
}

void print_list(myArr* head, int iter) {
    myArr* current = head;
    int counter = 0;
    int counter1 = iter;
    while (counter < iter) {
        printf_s("Key %d - %d\n", ++counter, current->val);
        myArr* current1 = Clone(current);
        for (int i = 0; i<iter; i++){
            current1 = current1->next;
        }
        printf_s("Key %d - %d\n", ++counter1, current1->val);
        current = current->next;
    }
}


void push(myArr* head, int val) {

    myArr* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(myArr));
    current->next->val = val;
    current->next->next = NULL;
}

int main() {

    myArr *head = NULL;
    head = malloc(sizeof(myArr));

    if (head == NULL) {
        return 1;
    }

    int iterNum;
    printf("Add integer number: ");
    scanf_s("%d", &iterNum);


    int number;
    printf("\nAdd some number: ");
    scanf_s("%d", &number);


    head->val = number;
    head->next = NULL;

    int counter = 1;
    while (counter < iterNum*2) {
        int num;
        printf("Add some number: ");
        scanf_s("%d", &num);
        push(head, num);
        counter++;
    }

    print_list(head, iterNum);

    return 0;

}
