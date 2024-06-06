#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, a[1000];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of Products: ");
    scanf("%d",&n);

    srand(time(0));  // Seed for randomness
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("Product ID:\t%d\n", a[i]);
    }

    bubbleSort(a, n);
    
    printf("\nSorted Product ID List:\n");
    printArray(a, n);

    printf("Enter the Product ID to be searched: ");
    scanf("%d", &key);

    starttime = clock();
    int pos = binarySearch(a, n, key);
    endtime = clock();

    if (pos != -1) {
        printf("Product found!!\nProduct %d found in position %d\n", key, pos + 1);
    } else {
        printf("Search failed\n%d not found\n", key);
    }

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", clk);

    return 0;
}