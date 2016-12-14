# Computational Intelligence (CI)

## Genetic Algorithms (GA) to resolve cryptarithmetic problem

This is a project of the discipline Computational Intelligence (CI) at Federal University of Uberlandia (UFU - Universidade Ferderal de Uberlândia). 

This project consists in implements an Genetic Algorithms (GA) to resolve cryptarithmetic problem. The full description of the requisits of this projects can be found at: docs/TrabalhoIntColetiva_2016_2.pdf.

The path code cointains the codes developed to resolv this problem.

To execute the code, you just have to type in terminal:

```bash
> gcc AG.c -o exec
> ./exec 0 0 0 1
```
The code expects 4 arguments:
  - First: type of crossover:
    - 0: Crossover cyclic 
    - 1: Crossover PMX
  - Second: type of selection:
    - 0: Tournment 
    - 1: Roulette
  - Third: type of einsertion:
    - 0: Sorted
    - 1: Elitism
  - Fourth: type of cryptarithmetic problem:
    - 1: send + more = money
    - 2: eat + that = apple
    - 3: cross + roads = danger
    - 4: coca + cola = oasis
    - 5: donald + gerald = roberts

The report/report.pdf shows the experimental results.
