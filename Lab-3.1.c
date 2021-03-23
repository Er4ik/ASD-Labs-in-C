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

void push(myArr* head, int val) {
    myArr* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(myArr));
    current->next->val = val;
    current->next->next = NULL;
}

int calculateArr(myArr* head) {
    myArr* current = head;
    int counter = 0;
    while (current != NULL) {
        printf_s("Pointer - %d Value - %d\n", current, current->val);
        current = current->next;
        counter++;
    }
    return counter;
}

void printSomeElemArr(myArr *current, int counter) {
    for (int i = 0; i < counter; i++) {
        current = current->next;
    }
    printf_s("Pointer - %d Value - %d\n", current, current->val);
}

void printArr(myArr* head, int counter) {
    myArr* current = head;
    printf("\n");
    for (int i = 0; i < counter; i++) {
        printf_s("Pointer - %d Value - %d\n", current, current->val);
        printSomeElemArr(current, counter);
        current = current->next;
    }
}

myArr* delElem(myArr* elem) {
    myArr* pCount;
    pCount = elem->next;
    free(elem);
    return pCount;
}

void  FreeMemory(myArr* pArr) {
    pArr = delElem(pArr);
    if (pArr != NULL) FreeMemory(pArr);
}

int main() {

    myArr* head = NULL;
    head = malloc(sizeof(myArr));

    if (head == NULL) {
        return 1;
    }

    int iterNum;
    printf("Add integer number: ");
    scanf_s("%d", &iterNum);

    if(iterNum < 1) {
        printf("Add correct natural number: ");
        scanf_s("%d", &iterNum);
        while (iterNum < 1) {
            printf("Add correct natural number: ");
            scanf_s("%d", &iterNum);
        }
    }

    int number;
    printf("\nAdd some number: ");
    scanf_s("%d", &number);

    head->val = number;
    head->next = NULL;

    int counter = 1;
    while (counter < iterNum * 2) {
        int num;
        printf("Add some number: ");
        scanf_s("%d", &num);
        push(head, num);
        counter++;
    }

    int count = calculateArr(head);
    printArr(head, count / 2);

    FreeMemory(head);

    return 0;
}
