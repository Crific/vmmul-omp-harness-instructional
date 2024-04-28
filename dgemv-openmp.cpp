#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

 //  #pragma omp parallel
 //  {
   //   int nthreads = omp_get_num_threads();
   //   int thread_id = omp_get_thread_num();
    //  printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
    //  printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
   // }

   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings

    // Use OpenMP to parallelize the outer loop
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        double sum = 0.0;

        // Compute the sum of A's row elements multiplied by vector x's elements
        for (int j = 0; j < n; j++) {
            sum += A[i * n + j] * x[j]; // Accessing A[i, j] in row-major order
        }

        // Update y[i] with the calculated sum
        // Critical section is necessary if multiple threads might write to the same y[i] at once
        // In this case, each thread writes to a different y[i], so it's inherently thread-safe
        #pragma omp atomic
        y[i] += sum;
    }
}
 
