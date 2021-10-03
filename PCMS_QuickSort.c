#include <stdio.h>

void QuickSort (int *arr, int Left, int Right) {

    int l = Left;
    int r = Right;
    int mid = arr[(l + r) / 2];
    int buf;
    while (l <= r){
        while (arr[l] < mid) {
            l++;
        }
        while (arr[r] > mid) {
            r--;
        }
        if (arr[l] >= arr[r]){
            buf = arr[l]; 
            arr[l] = arr[r];
            arr[r] = buf;
            l++; r--;
        }
    } 
    if (l < Right) {
        QuickSort(arr, l, Right);
    }
    if (r > Left) {
        QuickSort(arr, Left, r);
    }
}
int main(int argc, char * argv[]) {
    int quan_num, i, buf;
    int arr[110] = {};
    FILE *fin;
    fin = fopen("/Users/artemparfenov/Desktop/sum_in.txt", "r");
    fscanf(fin, "%d", &quan_num);
    for (i = 0; i < quan_num; i++) {
        fscanf(fin, "%d", &buf);
        arr[i] = buf;
    }
    for (int i = 0; i < quan_num + 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    QuickSort(arr, 0, quan_num - 1);
    for (i = 0; i < quan_num; i++) {
        printf ("%d ", arr[i]);
    }
    fclose(fin);
    return 0;
}
