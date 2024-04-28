/* 
 * CP#3 Vectorization Requirements
 *
 * Basic idea:
 * - Write a solid dgemv-basic.cpp code.
 * - Transplant that code into dgemv-vectorized.cpp.
 * - Let the compiler vectorize the code.
 *
 * Do not:
 * - Loop unroll your code.
 * - Use any OpenMP pragmas (they won't work at all here).
 *
 * Issues to consider:
 * - Did your code vectorize?
 * - How can you tell?
 * - How do you fix it if it did not vectorize?
 *
 */
const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

void my_dgemv(int n, double* A, double* x, double* y) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0; 
        double* rowA = A + i * n; // Pointer to the start of the i-th row in A

        
        for (int j = 0; j < n; j++) {
            sum = sum + rowA[j] * x[j]; 
        }
        
        y[i] = y[i] + sum; 
    }
}

