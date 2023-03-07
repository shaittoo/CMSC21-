/*Prints int and float values in various formats*/

#include <stdio.h> //includes standard input/output library

int main(void) //main function that takes no argument
{
    int i; //declares integer variable i
    float x; //declares float variable x

    i = 40; //assign the value i to 40
    x = 839.21f; //assign the value x to 839.21 as a float

    // Print the values of i in various formats
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);

    /*
        %d specifier for integers
        %5d specifies a width of 5 characters, so three spaces are added to the left of the number
        %-5d specifies a width of 5 characters, so two spaces are added to the right of the number
        %5.3d specifies a width of 5 characters, with leading zeros added to fill the width, and only the three least significant digits of the integer value shown
    */

    // Print the value of x in various formats
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);

    /*
        %f is a specifier for floating point numbers
        %e is a specifier for floating point numbers in scientific notation
        %g is a specifier that automatically chooses between %f and %e, depending on the magnitude of the number
        %10.3f specifies a width of 10 characters, with 3 decimal places shown
        %10.3e specifies a width of 10 characters, with 3 decimal places shown in scientific notation
        %-10g specifies a width of 10 characters, with the value left-justified and shown in either %f or %e format
    */

    return 0; // indicate successful program termination
}
