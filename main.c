#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <gmp.h>

#define PRECISION 25

int rank, size;

int main(int argc, char* argv[]){

    // File with the numbers found.
    FILE* result;

    // Declaration of variables.
    mpz_t fibo, last, penlt;

    // Attribution of variables.
    mpz_init_set_str(fibo, "1", 10);
    mpz_init_set_str(last, "1", 10);
    mpz_init_set_str(penlt, "1", 10);

    // Nth Fibonacci number found.
    int n_fib = 0;

    // Start of parallel execution.
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    while(1){

        // Find the next Fibonacci number.
        mpz_add(fibo, last, penlt);
        mpz_set(penlt, last);
        mpz_set(last, fibo);

        // Choose a thread to check if the Fibonacci number is prime.
        if((n_fib % size) == rank){

            // Check if the Fibonacci number is prime.
            if(mpz_probab_prime_p(fibo, PRECISION)){

                // Time that the number was found.
                system("DAY=$(date +%c) && echo [$DAY] >> result_file");

                // Write number found in the file.
                result = fopen("result_file", "a");
                mpz_out_str(result, 10, fibo);
                fputs("\n\n", result);
                fclose(result);

            }

        }

        n_fib++;

    }

    // End of parallel execution.
    MPI_Finalize();

}
