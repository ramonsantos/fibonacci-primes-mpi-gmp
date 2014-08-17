#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <gmp.h>

#define PRECISAO 25

int rank, size;

int main(int argc, char* argv[]){
    
    //Arquivo com os números encontrados.
    FILE* resultado;
    
    //Declaração
    mpz_t fibo, ultm, penl;
    
    //Atribuição
    mpz_init_set_str(fibo, "1", 10);
    mpz_init_set_str(ultm, "1", 10);
    mpz_init_set_str(penl, "1", 10);
    
    // 'n'º número de Fibonacci encontrado.
    int n_fib = 0;
    
    //Inicio da parte paralela.
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    while(1){
        
        //Encontra o próximo número em 'fibo'.
        mpz_add(fibo, ultm, penl);
        mpz_set(penl, ultm);
        mpz_set(ultm, fibo);        
    
        // Escolhe a thread para verificar a primaridade.
        if((n_fib % size) == rank){
            
            //Testa se o número encontrado é primo.
            if(mpz_probab_prime_p(fibo, PRECISAO)){

                //Imprime a data e hora que o número foi encontrado no arquivo.
                system("DIA=$(date +%c) && echo [$DIA] >> resultado2");

                //Imprime o número encontrado, no arquivo.
                resultado = fopen("resultado", "a");
                mpz_out_str(resultado, 10, fibo);            
                fputs("\n\n", resultado);
                fclose(resultado);

            }
            
        }
        
        n_fib++;
    }
    
    // 'Fim' da parte paralela
    MPI_Finalize();

}
