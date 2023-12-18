#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(double[]);
void insertion(double[]);
void quick(double [], int, int);
void insertion(double []);
void mergeSort(double[], int, int);
void merge(double[], int, int, int);
void selection(double[]);
int partition(double[], int, int);

int arrSize=10000;
double A1[10000];
//double B[200000];
double C[10000];
double D[10000];

int main() {
    for(int i=0; i<arrSize;i++) {
        A1[i] = rand()%1000; //double from 100-1000
        A1[i]=(double)A1[i];
    }
    /*
    for(int i=0; i<arrSize;i++) {
        B[i] = rand()%1000; //double from 100-1000
        B[i]=(double)B[i];
    }
    */
    for(int i=0; i<arrSize;i++) {
        C[i] = rand()%1000; //double from 100-1000
        C[i]=(double)C[i];
    }
    
    for(int i=0; i<arrSize;i++) {
        D[i] = rand()%1000; //double from 100-1000
        D[i]=(double)D[i];
    }
    
    //display(A1);
    clock_t begin = clock();
    insertion(A1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //display(A1);
    printf("Time spent %f", time_spent);
    printf("\n\n");
    
    /*
            Merge sort not working, I think because of 
            for (j=0;j<n2;j++) {
                R[j]=A[q+j+1]; }
            or because of how q is calculated
    display(B);
    clock_t begin3 = clock();
    mergeSort(B,1,arrSize-1);
    clock_t end3 = clock();
    double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
    display(B);
    printf("Time spent %f", time_spent3);
    printf("\n\n");
    */

    //display(C);
    clock_t begin1 = clock();
    quick(C,1,arrSize-1);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    //display(C);
    printf("Time spent %f", time_spent1);
    printf("\n\n");


    //display(D);
    clock_t begin2 = clock();
    selection(D);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    //display(D);
    printf("Time spent %f", time_spent2);
    printf("\n\n");

   return 0;
}

void swap(double *x, double *y) {
    double temp=*x;
    *x=*y;
    *y=temp;
}

void insertion(double A[]) {
    int i, j, key;
    for(j=2;j<arrSize;j++) {
        key=A[j];
        i = j-1;
        while (i>0 && A[i]>key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void mergeSort(double A[], int p, int r) {
    if(p<r) {
        int q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
    /*    int q;
    if(p<r) {
        q=floor((p+r)/2);
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }*/
}

void merge(double A[], int p, int q, int r) {
    int i,j,k, n1, n2;
    n1= q-p+1;
    n2= r-q;

    double L[n1], R[n2];

    for (i=0;i<n1;i++) {
        L[i]=A[p+i];
    }
    for (j=0;j<n2;j++) {
        R[j]=A[q+j+1];
    }
    i=0;
    j=0;
    for (k=p; k<r; k++) {
        if (L[i]<=R[j]) {
            printf("\nCheck %f", A[k]);
            A[k]=L[i];
            printf("\nCheck %f", A[k]);
            i++;
        }
        else{
            printf("\nbefore %f", A[k]);
            A[k]=R[j];
            printf("\nafter %f", A[k]);
            j++;
        }
    }
}


int partition(double A[], int p, int r) {
    int x=A[r];
    int i,j;
    i=p-1;
    for(j=p;j<=r-1;j++) {
        if (A[j]<=x){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return(i+1);
}

void quick(double A[], int p, int r) {
    if(p<r) {
        int q = partition(A,p,r);
        quick(A, p, q-1);
        quick(A,q+1,r);
    }
}

void selection(double A[]) {
    int i, j, min;
    for(i=1;i<arrSize-1;i++) {
        min=i; //min<-i;
        for(j=i+1;j<arrSize;j++) {
            if(A[j]<A[min]) {
                min=j;
            }
        }
        if(min!=i) {
            swap(&A[min],&A[i]);
        }
    }
}

void display(double C[]) {
    for(int i=0; i<arrSize;i++){
        printf("%0.0f ", C[i]);
    }
    printf("\n");
}
