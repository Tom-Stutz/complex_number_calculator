/*******************************************************************************************
AUTHOR   : Tom Stutz
PROGRAM  : Complex_Number_Calculator
FILE NAME: main.c
NOTES    : terminal script that is developed for numerous 2x1 complex number operations.
LAST EDIT: THURSDAY MAR 15, 2024, 19:10
VERSION: 1.0.0
*******************************************************************************************/

#include "complex.h"


int main(void) {

#ifdef TESTING
//variables
complex_num num1 = {2, 6};
complex_num num2 = {3, -3};
complex_num added = {0,0};
complex_num mult = {0,0};
complex_num div = {0,0};
complex_num num1conj = {0,0};
polar_num num1polar = {0,0};

//perform operations
added = complex_add(num1, num2);
mult = complex_complex_mult(num1, num2);
num1conj = complex_conj(num1);
div = complex_div(num1, num2);
num1polar = complex_to_polar(num1);

//print to screen
printf("---------------------------------------\n");
printf("num1: %0.2lf%+0.2lfj\n", num1.r, num1.im);
printf("num2: %0.2lf%+0.2lfj\n", num2.r, num2.im);
printf("num1 + num2: %0.2lf%+0.2lfj\n", added.r, added.im);
printf("num1 * num2: %0.2lf%+0.2lfj\n",mult.r,mult.im);
printf("num1 in polar is: %lf/_%+lf\n",num1polar.Z,num1polar.theta_degress );
printf("num1*: %0.2lf%+0.2lfj\n", num1conj.r, num1conj.im);
printf("num1 / num2: %0.2lf%+0.2lfj\n",div.r,div.im);
printf("---------------------------------------\n");
#endif

#ifdef GENERAL
int usr_input = 0;
int kill = 0;

welcome();
do{
kill = 0;
usr_input = menu();
operation(usr_input);
printf("----------------------------------\n");
printf("press 1 to continue, any key to quit\n");
printf("----------------------------------\n");
scanf("%d", &kill);
fflush(stdin);
}while(kill == 1);

#endif



    return 0;
}


