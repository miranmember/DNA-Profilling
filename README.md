# DNA Profiling

This is a C++ program for DNA profiling using a doubly-linked list data structure. The program reads in DNA sequence data from two input files, a database file and a DNA file, and searches the database for matching DNA sequences. It includes a function for counting the number of occurrences of a given DNA sequence in a given DNA strand. The program can handle both large and small database files.


## How to Compile and Run

To compile the program, navigate to the directory containing the source code and use the following command:
```
g++ -std=c++11 -o dna application.cpp
```
To run the program, use the following command:
```
./dna
```
Alternatively, You can also use the makefile to run the program


## Input files

The program will prompt you to enter the names of the database file and the DNA file. Enter the names of the files you wish to use, and the program will search the database for matching DNA sequences in the DNA file and output the results.

The program expects two input files: a database file and a DNA file.
Which are given in the repository, alternativly you can create your own.

## Output
The program will print a match if it is found.

## Example
```
Welcome to the DNA Profiling App!
Enter database file: large.txt
Enter dna file: 5.txt

Searching database...
DNA match: Lavender
```
