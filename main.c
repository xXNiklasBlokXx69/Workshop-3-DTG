#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main(void){
    int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Given list \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("The sorted list \n");
    printList(L, L_size);
    return 0;
}

void Merge(int L[], int start, int end, int mid){
    /*Here goes your code*/
    int len_1 = mid - start + 1;
    int len_2 = end - mid;
    int L1[len_1], L2[len_2];

    //Make the arrays L1 and L2
    for (int i = 0; i < len_1; i++) {
        L1[i] = L[start + i];
    }
    for (int j = 0; j < len_2; j++) {
        L2[j] = L[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while(i < len_1 && j < len_2) {
        if(L1[i] <= L2[j]) {
            L[k] = L1[i];
            i++;
        }else {
            L[k] = L2[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of L1, if any
    while (i < len_1) {
        L[k] = L1[i];
        i++;
        k++;
    }

    // Copy remaining elements of L2, if any
    while (j < len_2) {
        L[k] = L2[j];
        j++;
        k++;
    }

}

void MergeSort(int L[], int start, int end){
    /*Here goes your code as well*/
    if(start < end) {

        int m = (start + end) / 2;

        MergeSort(L, start, m);
        MergeSort(L, m + 1, end);

        Merge(L, start, end, m);
    }
}

void printList(int L[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", L[i]);
    printf("\n");
}