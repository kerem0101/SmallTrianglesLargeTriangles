#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct triangle
{
    int a;
    int b;
    int c;
};



typedef struct triangle triangle;



void swap(double* xp, double* yp, triangle* xtr, triangle* ytr)
{
    triangle tempTr;
    tempTr = *xtr;
    *xtr = *ytr;
    *ytr = tempTr;



   double temp = *xp;
    *xp = *yp;
    *yp = temp;
}



// A function to implement bubble sort
void bubbleSort(double arr[], int n, triangle* tr)
{
    int i, j;
    for (i = 0; i < n - 1; i++){

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1], &tr[j], &tr[j+1]);
            }
        }
    }
}




void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    double p, s[n];
    
    for (int i = 0; i<n; i++){
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        s[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
    }
    
    bubbleSort(s, n, tr);
}



int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}
