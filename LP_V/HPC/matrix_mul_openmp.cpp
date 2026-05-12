#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rowsA >> colsA;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int *A = new int[rowsA * colsA];
    int *B = new int[rowsB * colsB];
    int *C = new int[rowsA * colsB];

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rowsA * colsA; i++)
        cin >> A[i];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rowsB * colsB; i++)
        cin >> B[i];

    // OpenMP parallel matrix multiplication
    #pragma omp parallel for
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += A[i * colsA + k] * B[k * colsB + j];
            }
            C[i * colsB + j] = sum;
        }
    }

    cout << "\nResultant Matrix C:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << C[i * colsB + j] << " ";
        }
        cout << endl;
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}