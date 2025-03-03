#include <stdio.h>

int prienik(int *ar1, int n1, int *ar2, int n2, int *pr) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (ar1[i] == ar2[j]) {
                pr[k] = ar1[i];
                k++;
                break;
            }
        }
    }
    return k;
}

int zjednotenie(int *ar1, int n1, int *ar2, int n2, int *zj) {
    int k = 0;

    for (int i = 0; i < n1; i++) {
        zj[k] = ar1[i];
        k++;
    }

    for (int i = 0; i < n2; i++) {
        int j;
        for (j = 0; j < n1; j++) {
            if (ar2[i] == ar1[j]) {
                break; 
            }
        }
        if (j == n1) { 
            zj[k] = ar2[i];
            k++;
        }
    }

    return k;
}

int main() {
    int setpc1[] = {1, 2, 3};
    int setpc2[] = {3, 4, 5};
    int pr[3], zj[6]; 

    int size1 = sizeof(setpc1) / sizeof(setpc1[0]);
    int size2 = sizeof(setpc2) / sizeof(setpc2[0]);

    int pr_size = prienik(setpc1, size1, setpc2, size2, pr);
    int zj_size = zjednotenie(setpc1, size1, setpc2, size2, zj);

    printf("Prienik: { ");
    for (int i = 0; i < pr_size; i++) printf("%d ", pr[i]);
    printf("}\n");

    printf("Zjednotenie: { ");
    for (int i = 0; i < zj_size; i++) printf("%d ", zj[i]);
    printf("}\n");

    return 0;
}
