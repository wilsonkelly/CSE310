#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swapped;
int i;
int perf, perf2;
int n=10;
int best[] =    {1,2,3,4,5,6,7,8,9,10};
int worst[] =   {10,9,8,7,6,5,4,3,2,1};
int avg[] =     {1,3,2,4,6,5,8,7,10,9};
int best2[] =   {1,2,3,4,5,6,7,8,9,10};
int worst2[] =  {10,9,8,7,6,5,4,3,2,1};
int avg2[] =    {1,3,2,4,6,5,8,7,10,9};
int temp;

void SORT_V1_A();
void SORT_V2_A();
void display(int[]);

int main() {
    printf("V1 best");
    SORT_V1_A(best);
    printf("\nV1 worst");
    SORT_V1_A(worst);
    printf("\nV1 avg");
    SORT_V1_A(avg);
    printf("\nV2 best");
    SORT_V2_A(best2);
    printf("\nV2 worst");
    SORT_V2_A(worst2);
    printf("\nV2 avg");
    SORT_V2_A(avg2);
    display(best);
    display(worst);
    display(avg);
    display(best2);
    display(worst2);
    display(avg2);
}

void SORT_V1_A(int A[]) {
    perf=0;
    perf2=0;
    n=10;
    do {
        swapped = 0;
        i = 1;
        while (i<n) {
            if  (A[i-1]>A[i]) {
                temp = A[i-1]; //swap 
                A[i-1]=A[i];
                A[i]=temp;
                swapped = 1;
            }
            i++;
            perf++;
        }
        perf2++; 
    } while (swapped);
    printf("\ni<n: %d", perf);
    printf("\nn: %d", perf2);
    printf("\n");
}

void SORT_V2_A(int A[]) {
    perf=0;
    perf2=0;
    n=10;
    do {
        swapped = 0;
        i = 1;
        while (i<n) {
            if  (A[i-1]>A[i]) {
                temp = A[i-1]; //swap 
                A[i-1]=A[i];
                A[i]=temp;
                swapped = 1;
            }
            i++;
            perf++;
        } 
        n--;
        perf2++;
    } while (swapped);
    printf("\ni<n: %d", perf);
    printf("\nn: %d", perf2);
    printf("\n");
}

void display(int C[]) {
    for(int i=0; i<10;i++){
        printf("%d ", C[i]);
    }
    printf("\n");
}