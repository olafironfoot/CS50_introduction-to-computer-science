/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: comment me (to ensure user keys in number of pseudonumbers to generate and a "seed")
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: comment me (Converts the number after commandline argument ./generate to an int and define "n" as it's variable)
    int n = atoi(argv[1]);

    // TODO: comment me (If user has decided to include a "Seed" on the third commandline argment, convert that into int and plug it into function, "srand48()")

    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    // (otherwise it will use the current time in seconds to produce a random number, since its always changing)
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: comment me (prints number of int according to "n"-declared above- for each pass, prints a decimal between 0.0 and 1.0 * LIMIT defined as 65536 * int so we print and int)
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}