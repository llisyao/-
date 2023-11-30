#include <stdio.h>
#include <stdlib.h>

struct list {
    int inf;
    struct list* next;
};

struct list* enterList(struct list* F) {
    struct list* P, * T;
    F = P = T = NULL;
    while (1) {
        T = (struct list*)malloc(sizeof(struct list));
        T->next = NULL;
        if (!scanf_s("%d", &T->inf))
            break;
        if (F == NULL) {
            F = T;
            P = T;
        }
        else {
            P->next = T;
            P = T;
        }
    }
    return F;
}

static struct list* newList(struct list* F) {
    struct list* PU, * U, * twoF, * FF, * L;

    twoF = U = L = NULL;
    int b = 1;
    PU = F;
    FF = F;

    while (PU->next != NULL) {
        U = PU->next;
        if (U->inf > b) {
            PU->next = U->next;
            U->next = NULL;
            if (twoF == NULL) {
                twoF = U;
            }
            else {
                L = twoF;
                while (L->next) {
                    L = L->next;
                }
                L->next = U;
            }
        }
        else {
            PU = U;
        }
        b++;
    }
    if (F->inf > 1) {
        F = F->next;
        FF->next = twoF;
        twoF = FF;
    }
    return twoF;
}

void listFree(struct list* F) {
    struct list* T;
    for (T = F; F != NULL; T = F) {
        F = F->next;
        free(T);
    }
}

void pinList(struct list* F) {
    struct list* T;
    for (T = F; T != NULL; T = T->next)
        printf("%d ", T->inf);
}

void main() {
    struct list* F, * P, * T, * twoF;
    F = P = T = twoF = NULL;

    F = enterList(F);
    if (F == NULL) {
        printf("NULL");
        return;
    }

    twoF = newList(F);
    printf("INlist\n");
    pinList(F);

    printf("\nOUTlist\n");
    pinList(twoF);

    listFree(F);
    listFree(twoF);
}