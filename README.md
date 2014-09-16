fibonacci-primes-mpi-gmp
========================

#Como Compilar
$ mpicc -I/opt/local/include -L/opt/local/lib -lgmp main.c -o main

#Como Rodar
$ mpirun -np N ./main

Onde 'N' é o número de threads
