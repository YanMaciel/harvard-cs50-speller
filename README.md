# Academic Honesty
If you are taking Harvard's CS50 - Introduction to Computer Science course you **must follow the course's [Academic Honesty philosophy](https://cs50.harvard.edu/x/2021/honesty/)**.

It is not reasonable to access a solution to some assessement prior to (re-)submitting your own.

The essence of all work that you submit to the CS50 course **must be your own**. 

# Speller
In this exercise, the challenge was to implement the fastest spell checker that I could using a hash table function.

# System Algorithm (How it operates)
This is a command-line application and it was fully developed in **C**.

The program is designed to spell-check a file after loading a dictionary of words from disk into memory.

The challenge was to implement, in order, the functions: load, hash, size, check, and unload as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. 
  
  1. Record preference if vote is valid:
  
    bool vote(int voter, int rank, string name);
    
  2. Tabulate votes for non-eliminated candidates:
  
    void tabulate(void);
    
  3. Print the winner of the election, if there is one:
  
    bool print_winner(void);
    
  4. Return the minimum number of votes any remaining candidate has:

    int find_min(void);
    
  5. Return true if the election is tied between all candidates, false otherwise:

    bool is_tie(int min);
  
# What I Learned
In this exercise, I learned how to apply a good hash table function to better search through the dictionary the words from the text file to spell check.

To engage in such exercise, first I needed to dive into Data Structures pool of knowledge: pointers, nodes, arrays, linked lists, trees, hash tables, hash tables functions, tries, first-in-first-out (FIFO), and more. 

Also, I was once again capable of handling different files with C to implement this aplication.

# Usage
To use and test this program, you will need [CS 50 Library](https://cs50.readthedocs.io/libraries/cs50/c/). Copy this repository and through the command line, enter the program's folder and run the following command to compile:

$ make runoff

Then you run the program in the command-line as bellow:

    ./runoff <candidate 1> <candidate 2> <candidate 3> ... <candidate n>
    
Example:

