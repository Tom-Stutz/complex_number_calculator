/*
Header
123456

*/

#include "complex.h"

/*******
FUNCTION: complex_add
INPUTS: input1, input2
OUTPUTS: output
DESCRIPTION: takes 2 inputs of complex_num type and adds them together. Returns a complex_num type
*******/
complex_num complex_add (complex_num input1,complex_num input2) {

//variables
complex_num output;
//addition
output.r = input1.r + input2.r;
output.im = input1.im + input2.im;
//return
return output;

}

/*******
FUNCTION: complex_subtrack
INPUTS: input1, input2
OUTPUTS: output
DESCRIPTION: takes 2 inputs of complex_num type and subtracts them together (input 1 - input 2). Returns a complex_num type
*******/
complex_num complex_subtract(complex_num input1,complex_num input2) {

//variables
complex_num output;
//addition
output.r = input1.r - input2.r;
output.im = input1.im - input2.im;
//return
return output;

}

/*******
FUNCTION: complex_to_polar
INPUTS: input
OUTPUTS: output
DESCRIPTION: Takes an input of complex_num type and returns an output of polar_num type.
*******/
polar_num complex_to_polar(complex_num input) {

//variables
polar_num output = {0,0};
double theta_radians = 0;

//perform operations
output.Z = sqrt(pow(input.r, 2) + pow(input.im, 2));
theta_radians = atan(input.im / input.r);
output.theta_radians = theta_radians;
output.theta_degress = (theta_radians * 180)/ M_PI;

return output;

}

/*******
FUNCTION: complex_complex_mult
INPUTS: input1, input2
OUTPUTS: output
DESCRIPTION: Takes two inputs of complex_num type, multiplies them, and returns an output of complex_num type.
*******/
complex_num complex_complex_mult(complex_num input1,complex_num input2) {

//variables
complex_num output = {0,0};
output.r = (input1.r*input2.r) - (input1.im*input2.im);
output.im = (input1.r*input2.im) + (input1.im*input2.r);

return output;

}

/*******
FUNCTION: complex_conj
INPUTS: input1, input2
OUTPUTS: output
DESCRIPTION: Takes an input of complex_num type, and takes the complex conjugate, returns complex_num type
*******/
complex_num complex_conj(complex_num input) {
//variables
complex_num output = {0,0};

output.r = input.r;
output.im = -1 * input.im;


return output;


}

/*******
FUNCTION: complex_div
INPUTS: input1, input2 (input1/input2)
OUTPUTS: output
DESCRIPTION: Takes two inputs of complex_num type, divides them, and returns an output of complex_num type.
*******/
complex_num complex_div (complex_num input1,complex_num input2) {
//variables
complex_num output = {0,0};
complex_num numer = input1;
complex_num denom = input2;
numer = complex_complex_mult(numer, complex_conj(denom));
denom = complex_complex_mult(denom, complex_conj(denom));
output.r = numer.r / denom.r;
output.im = numer.im / denom.r;

return output;
}


/*******
FUNCTION: welcome
INPUTS: n/a
OUTPUTS: n/a
DESCRIPTION: Welcome screen for program
*******/
void welcome(void) {
printf("\n\n\t-----------------------------------------------------------\n\n");
printf("\tWelcome to The Complex Number Calculator\n");
printf("\t(because who thought you would need one of these)");
printf("\n\n\t-----------------------------------------------------------\n\n");

}


/*******
FUNCTION: menu
INPUTS: n/a
OUTPUTS: user_input
DESCRIPTION: menu for program, returns menu choice
*******/
int menu(void) {
//variables
int user_input = 0;
int flag = 0;
//print options
do { 
printf("1x2 Input Operations\n");
printf("1) + (complex complex addition)\n");
printf("2) - (complex complex subtraction)\n");
printf("3) * (complex complex multiplication)\n");
printf("4) / (complex complex division)\n");
printf("5) a* (complex conjugate)\n");
printf("6) ->polar (Convert to Polar)\n");
printf("----------------------------------\n");

flag = scanf("%d", &user_input);
if(!flag || !(user_input > 0 && user_input <= 6)) {
    printf("ERROR. Please select a valid menu option\n");
    flag = 0;
    fflush(stdin);
}

} while(!flag || !(user_input > 0 && user_input <= 6));

//return input
return user_input;

}

/*******
FUNCTION: operation
INPUTS: menu_input
OUTPUTS: n/a
DESCRIPTION: performs chosen operation and prints results to screen.
*******/
void operation(int menu_input) {
    //variables
    complex_num num1 = {0,0};
    complex_num num2 = {0,0};
    

    switch(menu_input) {
        case 1:
        num1 = usr_input();
        num2 = usr_input();
        printf("%lf%+lfj + %lf%+lfj = %lf%+lfj\n\n", num1.r, num1.im, num2.r, num2.im, complex_add(num1,num2).r, complex_add(num1,num2).im);
        printf("----------------------------------\n");
        break;
        case 2:
        num1 = usr_input();
        num2 = usr_input();
        printf("%lf%+lfj - %lf%+lfj = %lf%+lfj\n\n", num1.r, num1.im, num2.r, num2.im, complex_subtract(num1,num2).r, complex_subtract(num1,num2).im);
        printf("----------------------------------\n");
        break;
        case 3:
        num1 = usr_input();
        num2 = usr_input();
        printf("%lf%+lfj * %lf%+lfj = %lf%+lfj\n\n", num1.r, num1.im, num2.r, num2.im, complex_complex_mult(num1,num2).r, complex_complex_mult(num1,num2).im);
        printf("----------------------------------\n");
        break;
        case 4:
        num1 = usr_input();
        num2 = usr_input();
        printf("%lf%+lfj / %lf%+lfj = %lf%+lfj\n\n", num1.r, num1.im, num2.r, num2.im, complex_div(num1,num2).r, complex_div(num1,num2).im);
        printf("----------------------------------\n");
        break;
        case 5:
        num1 = usr_input();
        printf("(%lf%+lfj)* = %lf%+lfj\n\n", num1.r, num1.im, complex_conj(num1).r, complex_conj(num1).im);
        printf("----------------------------------\n");
        break;
        
        case 6:
        num1 = usr_input();
        printf("(%lf%+lfj) ->plar = Z = %lf, Theta = %lf degrees (%lf radians)\n\n", num1.r, num1.im, complex_to_polar(num1).Z, complex_to_polar(num1).theta_degress,complex_to_polar(num1).theta_radians);
        printf("----------------------------------\n");
        break;


        default:
        printf("Something happened\n");
        break;

    }



}

/*******
FUNCTION: usr_input
INPUTS: n/a
OUTPUTS: complex_num
DESCRIPTION: takes user input from stdin for complex numbers
*******/
complex_num usr_input(void) {
//variables
complex_num usr_input = {0,0};
int flag = 0;

do{
    printf("Input complex number in form \"a,bj\" (where a is the real part and b is the imaginary part)\n");
    flag = fscanf(stdin,"%lf,%lfj", &usr_input.r,&usr_input.im);
    if(!(flag == 2)) {
        printf("ERROR. Input a valid format\n");
        flag = 0;
        fflush(stdin);
    }
} while(!(flag == 2));

return usr_input;
}