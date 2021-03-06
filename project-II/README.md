# Computational Intelligence (CI)

## Artifical Neural Network

This is a project of the discipline Computational Intelligence (CI) at Federal University of Uberlandia (UFU - Universidade Ferderal de Uberlândia). 

This project consists in implements an artifical neural network (ANC) to recognize some digits: 0 to 5. The full description of the requisits of this projects can be found at: docs/Trabalho_Perceptron_2015_2.pdf.

The project consists in three steps:
- Create a perceptron ANC with one (1) neuron to recognize the digits 0 and 1.
- Create a perceptron ANC with two (2) neurons to recognize the digits 0 and 1.
- Create a perceptron ANC with six (6) neurons to recognize the digits: 0 to 5.

The implementation of each step can be found at:
- codes/ex1.py
- codes/ex2.py
- codes/ex3.py

For example, if you want to execute the file ex1.py you can just type this command on terminal:
```bash
> python ex1.py
```
The results should have this format:
```bash
Epochs of training = 1
00.txt
[0]
01.txt
[0]

.
.
.

59.txt
[1]
```
This results indicates:
- How many epochs of training the perceptron spends to learn
- For each test file : (00.txt to 59.txt) at tests/ what perceptron recognized.
  - For example
    - This part:
    ```bash
    01.txt
    [0]
    ```
    Indicates that ANC recognize the input of file 01.txt as a digit 0.
    

The report/report.pdf shows the experimental results.
