#include <stdio.h>
#include <stdlib.h>

int main2() {
    int x = 7, *ip, y;
    ip = &x;
    *ip = *ip + 3;
    printf("ip=%p, *ip=%d, x=%d\n", ip, *ip, x);
    // we know that x = 10
    y = x;
    y = y + 6;
    printf("x=%d and y=%d\n", x, y);
    printf("Address of x=%p and y=%p\n", &x, &y);
    ip = x;
    printf("ip=%p ip=%u\n", ip, ip);
    return 0;
}

int main3() {
    int arr[5] = {1, 2, 33, 44, 55};
    int *ap = arr, i;
    void *vp;
    printf("first element in the array=%d\n", *ap);
    printf("third element=%d\n", *ap+2); // value of first element + 2
    printf("third element=%d\n", *(ap+2));
    printf("third element=%d\n", arr[2]);
    printf("arr=%p, ap=%p, &arr[0]=%p\n", arr, ap, &arr[0]);
    for (ap=arr; ap < arr + sizeof(arr)/sizeof(int); ap++) {
        printf("%d\n", *ap);
    }
    ap = 1000;
    ap++;
    printf("%u\n", ap);
    vp = 1000;
    vp++;
    printf("%u\n", vp);
}

int n;
int* first_n_numbers() {
    int *arr, i;
    printf("First how many? ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Unfortunately I can not give you that memory\n");
        return NULL;
    }
    for (i=0; i<n; i++) {
        arr[i] = i+1;
    }
    return arr;
}

int main() {
    int *a, i;
    a = first_n_numbers();
    for (i=0; i<n ;i++) {
        printf("%d  ", a[i]);
        if (i % 15 == 0)
            printf("\n");
    }
    printf("\n");
    printf("before free a=%p\n", a);
    free(a);
    a = NULL;
    printf("after free a=%p\n", a);
    a = first_n_numbers();
    free(a);
    // memory leak
    a = first_n_numbers();
    a = first_n_numbers();
    a = first_n_numbers();
    free(a);

}