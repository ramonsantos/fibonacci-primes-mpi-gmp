#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include<time.h>
#define PRECISAO 25
int main(){
    
    //Arquivo com os números encontrados.
    FILE* resultado;
    
    //Declaração
    mpz_t fibo, ultm, penl;
    
    //Atribuição
    mpz_init_set_str(fibo, "1", 10);
    mpz_init_set_str(ultm, "1", 10);
    mpz_init_set_str(penl, "1", 10);
    
    int encontrados = 0;
    
    while(1){
        
        //Encontra o próximo número em 'fibo'.
        mpz_add(fibo, ultm, penl);
        mpz_set(penl, ultm);
        mpz_set(ultm, fibo);

        //Testa seu o número encontrado é primo.
        if(mpz_probab_prime_p(fibo, PRECISAO)){
            
            //Imprime a hora que o número foi encontrado no arquivo.
            system("DIA=$(date +%c) && echo [$DIA] >> resultado");
  
            //Imprime o número encontrado no arquivo.
            resultado = fopen("resultado", "a");
            mpz_out_str(resultado, 10, fibo);            
            fputs("\n\n", resultado);
            fclose(resultado);
            
            //Imprime a quantidade de números encontrados no terminal.
            encontrados++;
            printf("%dº Número encontrado\n", encontrados);
            
        }
      
    }
   
}
