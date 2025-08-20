#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int elem[SIZE];
    int count;
} List;

List initialize();
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

List initialize() {
    List L;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    if (L.count >= SIZE) {
        printf("List is full.\n");
        return L;
    }
    if (position < 0 || position > L.count) {
        printf("Invalid position!\n");
        return L;
    }
    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        printf("Invalid position!\n");
        return L;
    }
    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count >= SIZE) {
        printf("Cannot insert.\n");
        return L;
    }
    int pos = 0;
    while (pos < L.count && L.elem[pos] < data) {
        pos++;
    }
    return insertPos(L, data, pos);
}

void display(List L) {
    printf("List elements: ");
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main() {
    List L = initialize();
    int num, position;

    printf("Enter int: ");
    scanf("%d", &num);

    printf("Enter position: ");
    scanf("%d", &position);

    L = insertPos(L, num, position);

    display(L);

    return 0;
}
