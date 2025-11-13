#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** copyMatrix(int** src, int n) {
    int** dest = createMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }
    return dest;
}

void rotateMatrix90(int** matrix, int n) {
    int** temp = copyMatrix(matrix, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = temp[n - 1 - j][i];
        }
    }
    deleteMatrix(temp, n);
}

void rotateMatrix180(int** matrix, int n) {
    rotateMatrix90(matrix, n);
    rotateMatrix90(matrix, n);
}

void rotateMatrix270(int** matrix, int n) {
    rotateMatrix90(matrix, n);
    rotateMatrix90(matrix, n);
    rotateMatrix90(matrix, n);
}

int findMaxSubmatrixSum(int** matrix, int n, int k) {
    if (k > n) return 0;
    int maxSum = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            int sum = 0;
            for (int di = 0; di < k; di++) {
                for (int dj = 0; dj < k; dj++) {
                    sum += matrix[i + di][j + dj];
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
