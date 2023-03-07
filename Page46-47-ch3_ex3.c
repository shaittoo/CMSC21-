/* Adds two fractions */
#include <stdio.h> // include standard input/output library

int main(void) //main function that takes no argument
{
    int num1, denom1, num2, denom2, result_num, result_denom; //declare integer variables for numerator, denominator, and result

    //Asks user to enter the first fraction and read the input
    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);

    //Asks user to enter the second fraction and read the input
    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);

    //Computes the sum of the two fractions
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    //Print the result of the computa /main function that takes no argumenttion
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0; // indicate successful program termination
}
