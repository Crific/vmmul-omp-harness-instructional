const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {
    // row i in matrix A
    for (int i = 0; i < n; i++) {

        // Initial sum for the row
        double sum = 0.0;
        
        // Compute the sum of A's row elements multiplied by vector x's elements
        for (int j = 0; j < n; j++) {
            // Summation of A[i, j] * x[j]
            sum += A[i * n + j] * x[j]; // Accessing A[i, j] in row-major order
        }
        // Update y[i] with the calculated sum
        y[i] += sum;
    }
}
