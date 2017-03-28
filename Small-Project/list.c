#include<stdlib.h>
#include<stdio.h>
#include"list.h"

bool checkIfNullPointer(List *list) {
    if (list->previous == NULL || list->next == NULL) {
        printf("List element contains NULL pointer\n");
        return true;
    }
    return false;
}

int getLabel(List *list) {
    return list->label;
}

List* getPrevious(List *list) {
    return list->previous;
}

List* getNext(List *list) {
    return list->next;
}

bool isEmpty(List *list) {
    if ((getLabel (list->previous) == -1) && (getLabel (list->next) == -1)) {
        return true;
    }
    else {
        return false;
    }
}

List* createListElement(int label) {
    List *list;
    list = (List*) malloc(sizeof(List));
    
    list->previous = list;
    list->next = list;
    list->label = label;
    
    return list;
}

void setConnection(List *firstList, List *secondList) {
    firstList->next = secondList;
    secondList->previous = firstList;
    return;
}

void deleteListElement(List *list) {
    free(list);
    return;
}
/*
int main() { 
    List list1, list2, list3, list;
    list1 = *create(1);
    list2 = *create(2);
    list3 = *create(3);
    printf("%d", getLabel(&list2));
    if (checkIfNullPointer(&list1)) {
        printf("Prawda");
    }
    else {
        printf("Fałsz");
    }
    setConnection(&list2, &list3);
    setConnection(&list2, &list1);
    setConnection(&list1, &list3);
    printf("%d", getLabel(getPrevious(&list2)));
    printf("%d", getLabel(getNext(&list2)));
    printf("%d", getLabel(getPrevious(&list1)));    
    printf("%d", getLabel(getNext(&list1)));
    printf("%d", getLabel(getPrevious(&list3)));
    printf("%d", getLabel(getNext(&list3)));
    return 0;
}
*/