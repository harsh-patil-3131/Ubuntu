#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024  // Matrix size (can be changed)

void matrix_add(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void initialize_matrix(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
        }
    }
}

int main() {
    static int A[N][N], B[N][N], C[N][N];

    srand(time(NULL));
    initialize_matrix(A);
    initialize_matrix(B);

    clock_t start = clock();
    matrix_add(A, B, C);
    clock_t end = clock();

    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

