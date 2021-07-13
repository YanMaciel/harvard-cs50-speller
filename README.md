# Academic Honesty
If you are taking Harvard's CS50 - Introduction to Computer Science course you **must follow the course's [Academic Honesty philosophy](https://cs50.harvard.edu/x/2021/honesty/)**.

It is not reasonable to access a solution to some assessement prior to (re-)submitting your own.

The essence of all work that you submit to the CS50 course **must be your own**. 

# CS50's Speller
In this exercise, the challenge was to implement the fastest spell checker that I could using a hash table function.

# How it works
This is a command-line application fully developed in **C**.

The program is designed to spell-check a file after loading a dictionary of words from disk into memory.

The challenge was to implement, in order, the functions: **load, hash, size, check, and unload** as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. 
  
# What I learned
In this exercise, I learned how to apply a good hash table function to better search through the dictionary the words from the text file to spell check.

To engage in such exercise, first I needed to dive into Data Structures pool of knowledge: pointers, nodes, arrays, linked lists, trees, hash tables, hash tables functions, tries, first-in-first-out (FIFO), and more. 

I was once again requested to handle different files with C to implement this aplication, allocating memory and freeing it after the program unloaded.

Learned how to use 'valgrind' to check for memory leaks.

Got a 100% grade in correctness, design and style in this exercise.

# Usage
To use and test this program, you will need [CS 50 Library](https://cs50.readthedocs.io/libraries/cs50/c/). Copy this repository and through the command-line, enter the program's folder and run the following command to compile:

$ make speller

You could therefore run your program on some text in one window, as with the below:

    $ ./speller texts/lalaland.txt
    
The output will contain the following data:

    WORDS MISSPELLED:
    WORDS IN DICTIONARY:
    WORDS IN TEXT:
    TIME IN load:
    TIME IN check:
    TIME IN size:
    TIME IN unload:
    TIME IN TOTAL:

