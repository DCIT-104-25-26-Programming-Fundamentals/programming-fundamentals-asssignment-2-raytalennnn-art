// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 10;

// Helper function to print a matrix cleanly
void printMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Helper function to read matrix elements from user
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a Matrix
void transposeMatrix(const int input[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices
void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "Select Matrix Operation:\n1. Transpose\n2. Addition\n3. Multiplication\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        int r, c;
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        int A[MAX][MAX], result[MAX][MAX];
        readMatrix(A, r, c);

        transposeMatrix(A, result, r, c);

        cout << "\nOriginal Matrix:\n";
        printMatrix(A, r, c);

        cout << "\nTransposed Matrix:\n";
        printMatrix(result, c, r);

    } else if (choice == 2) {
        int r, c;
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
        cout << "Enter Matrix A:\n";
        readMatrix(A, r, c);

        cout << "Enter Matrix B:\n";
        readMatrix(B, r, c);

        addMatrices(A, B, result, r, c);

        cout << "\nResultant Matrix (A + B):\n";
        printMatrix(result, r, c);

    } else if (choice == 3) {
        int r1, c1, r2, c2;
        cout << "Enter rows for Matrix A: ";
        cin >> r1;
        cout << "Enter columns for Matrix A: ";
        cin >> c1;

        cout << "Enter rows for Matrix B: ";
        cin >> r2;
        cout << "Enter columns for Matrix B: ";
        cin >> c2;

        if (c1 != r2) {
            cout << "Error: Columns of A must equal Rows of B for multiplication." << endl;
            return 0;
        }

        int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
        cout << "Enter Matrix A:\n";
        readMatrix(A, r1, c1);

        cout << "Enter Matrix B:\n";
        readMatrix(B, r2, c2);

        multiplyMatrices(A, B, result, r1, c1, c2);

        cout << "\nResultant Matrix (A x B):\n";
        printMatrix(result, r1, c2);
    }

    return 0;
}
