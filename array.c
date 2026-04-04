#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main() {
    //과제1) 
    int i;
    int A[N];
    int sum = 0, max, min;

    srand(time(NULL));
    for(i=0; i < N; i++) {
        A[i] = rand() % (N + 1);
        printf("%d ", A[i] );
    }
    
    printf("\n");

    for(i = N-1; i>= 0; i--) {
        printf("%d ", A[i]);
    }
    printf("\n");

    max = A[0];
    min = A[0];
    for(i = 0; i<N; i++) {
        sum += A[i];
        if(A[i] > max) {
            max = A[i];
        }
        if(A[i] < min) {
            min = A[i];
        }
    }
    
    printf("sum: %d\n", sum);
    printf("max: %d\n", max);
    printf("min: %d\n", min);
    
    //과제2)
    int B[N][N] = {0};
    int row = 0; 
    int col = N/2;
    int next_row, next_col;

    for(int i = 1; i <= N*N; i++) {
        B[row][col] = i;
        next_row = (row - 1 + N) % N;
        next_col = (col + 1) % N;
        if(B[next_row][next_col] != 0) {
            row = (row + 1) % N;
        } else {
            row = next_row;
            col = next_col;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < N; i++) {
        sum = 0;
        for(int j = 0; j < N; j++) sum += B[i][j];
        printf("row: %d sum: %d\n", i+1, sum);
    }
    for(int j = 0; j < N; j++) {
        sum = 0;
        for(int i = 0; i < N; i++) sum += B[i][j];
        printf("col: %d sum: %d\n", j+1, sum);
    }
    sum = 0;
    for(int i = 0; i < N; i++) sum += B[i][i];
    printf("diag: 1 sum: %d\n", sum);
    
    sum = 0;
    for(int i = 0; i < N; i++) sum += B[i][N - 1 - i];
    printf("diag: 2 sum: %d\n", sum);
    return 0;
}