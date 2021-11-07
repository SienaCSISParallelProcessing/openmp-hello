/* 

   Hello, World program for OpenMP.

   Jim Teresco, Siena College, Fall 2021

   Based on example by Blaise Barney, LLNL at
   https://hpc.llnl.gov/tuts/openMP/#ProgrammingModel
*/

#include <omp.h>
#include <stdio.h>

int main (int argc, char *argv[])  {

  // These variables will be used to store the number of threads and
  // thread ID for each when we enter a parallel code segment.
  int num_threads, thread_num;

  printf("Hello, World! from the start of the main function\n");
  
  // This compiler directive says that we want to create a team
  // of threads to run the subsequent code block in parallel.
  //
  // Each thread will get its own copy of each of the variables listed
  // in the private clause.
#pragma omp parallel private(num_threads, thread_num)
  {

    // Get our thread number -- will be 0 to num_threads - 1.
    thread_num = omp_get_thread_num();
    printf("Hello, World! from thread %d\n", thread_num);
    
    // We'll have only thread 0 print the number of threads.
    if (thread_num == 0) {
      num_threads = omp_get_num_threads();
      printf("Number of threads = %d\n", num_threads);
    }
    
  }
  // at this point, the team of threads all join back to the original
  // thread and only that original remains in existence.
  printf("Goodbye, World! from the original thread\n");

  return 0;
}
