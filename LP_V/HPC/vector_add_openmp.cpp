#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of vectors: ";
    cin >> n;

    int *A = new int[n];
    int *B = new int[n];
    int *C = new int[n];

    cout << "Enter elements of A:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter elements of B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    // OpenMP parallel addition
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }

    cout << "\nResultant vector:\n";
    for (int i = 0; i < n; i++)
        cout << C[i] << " ";
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}