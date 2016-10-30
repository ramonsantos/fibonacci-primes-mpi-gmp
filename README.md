# Números primos de Fibonacci

## Descrição
Este projeto foi desenvolvido durante uma disciplina de Sistemas Distribuídos. O projeto foi feito para rodar em Clusters e consiste em obter os números da sequência de Fibonacci e verificar se estes são números primos.

## Dependências

* [OpenMPI](https://www.open-mpi.org/) - Message Passing Interface
* [GMP](https://gmplib.org/) - GNU Multiple-Precision Library

## Como Compilar

```bash
  $ mpicc -I/opt/local/include -L/opt/local/lib -lgmp main.c -o main
```

## Como Rodar

```bash
$ mpirun -np N ./main
```
Onde 'N' é o número de threads

## Resultados

A aplicação foi executado duas vezes. Uma com apenas 1 thread e outra com 4 threads. A execução era interrompida quando eram encontrados 32 números.

| Threads | Números Encontrados | Tempo |
|---------|---------------------|-------|
|    1    |          32         | 11:47 |
|    4    |          32         |  6:59 |
