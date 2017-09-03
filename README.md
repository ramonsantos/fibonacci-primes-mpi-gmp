# Fibonacci prime

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d62643eb494d4eff9c85aebdde448ca6)](https://www.codacy.com/app/ramonsantos/fibonacci-primes-mpi-gmp?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ramonsantos/fibonacci-primes-mpi-gmp&amp;utm_campaign=Badge_Grade)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()

## Description

This project was developed during a Distributed Systems discipline. The project was made to run in Clusters. The purpose is to find the numbers in the Fibonacci sequence and check if they are prime numbers.

## Dependencies

* [OpenMPI](https://www.open-mpi.org/) - Message Passing Interface
* [GMP](https://gmplib.org/) - GNU Multiple-Precision Library

## How to compile

```bash
  $ mpicc -I/opt/local/include -L/opt/local/lib -lgmp main.c -o main
```

## How to run

```bash
  $ mpirun -np N ./main
```
Where '*N*' is the number of threads.

## Results

In this study, the application was executed the first time with one thread and the second time with four threads.
