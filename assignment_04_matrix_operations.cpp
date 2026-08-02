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
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void inputMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices(int matrix1[10][10], int matrix2[10][10], int rows, int cols);
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int rowsA, int colsA, int colsB);

int main()
{
    int matrix1[10][10], matrix2[10][10];
    int rows, cols;

   
    cout << "===== PART A: Matrix Transpose =====" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix:" << endl;
    inputMatrix(matrix1, rows, cols);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix1, rows, cols);

    cout << "\nTransposed Matrix:\n";
    transposeMatrix(matrix1, rows, cols);

    
    cout << "\n===== PART B: Matrix Addition =====" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter elements of Matrix 1:" << endl;
    inputMatrix(matrix1, rows, cols);

    cout << "Enter elements of Matrix 2:" << endl;
    inputMatrix(matrix2, rows, cols);

    cout << "\nMatrix 1:\n";
    displayMatrix(matrix1, rows, cols);

    cout << "\nMatrix 2:\n";
    displayMatrix(matrix2, rows, cols);

    cout << "\nSum of Matrices:\n";
    addMatrices(matrix1, matrix2, rows, cols);

    
    cout << "\n===== PART C: Matrix Multiplication =====" << endl;

    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns for Matrix A: ";
    cin >> colsA;

    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible." << endl;
    }
    else
    {
        cout << "Enter elements of Matrix A:" << endl;
        inputMatrix(matrix1, rowsA, colsA);

        cout << "Enter elements of Matrix B:" << endl;
        inputMatrix(matrix2, rowsB, colsB);

        cout << "\nMatrix A:\n";
        displayMatrix(matrix1, rowsA, colsA);

        cout << "\nMatrix B:\n";
        displayMatrix(matrix2, rowsB, colsB);

        cout << "\nProduct Matrix:\n";
        multiplyMatrices(matrix1, matrix2, rowsA, colsA, colsB);
    }

    return 0;
}

void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    displayMatrix(transpose, cols, rows);
}

void addMatrices(int matrix1[10][10], int matrix2[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    displayMatrix(sum, rows, cols);
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int rowsA, int colsA, int colsB)
{
    int product[10][10];

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    displayMatrix(product, rowsA, colsB);
}
