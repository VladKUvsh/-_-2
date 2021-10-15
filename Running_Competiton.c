#include <stdio.h>
#include <string.h>
int main (int argc,char * argv[]) {
    FILE *fin;
    int n, i, k;
    char arr[100] = {};
    char c;
    k = 0;
    fin = fopen("/Users/artemparfenov/Desktop/sum_out.txt", "r");
//    fout = fopen("", "w");
    fscanf(fin, "%d", &n);
    printf("%d\n", n);
    c = fgetc(fin);
    c = fgetc(fin);
    printf("Hello");
    fclose(fin);

    for (i = 0; i < k; i++) {
        while (arr[i + 1] != ' ') {
            strcat(&arr[i], &arr[i + 1]);
        }   
        i++;
    }
    for (i = 0; i < 6; i++) {
        printf("%c ", arr[i]);
    }
    return 0;
}
