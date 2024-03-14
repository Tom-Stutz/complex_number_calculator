/*
Header
*/


#ifndef __COMPLEX_H__
#define __COMPLEX_H__

//#define TESTING
#define GENERAL
//////////////////////////////////////////////////////////////////////////////////////
//Include libraries
//////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdint.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////////////
//global variables
//////////////////////////////////////////////////////////////////////////////////////
typedef struct {
    double r;
    double im;

} complex_num;

typedef struct {
    double Z;
    double theta_degress;
    double theta_radians;
} polar_num;

//////////////////////////////////////////////////////////////////////////////////////
//prototype functions
//////////////////////////////////////////////////////////////////////////////////////
complex_num complex_add(complex_num,complex_num);

complex_num complex_subtract(complex_num,complex_num);

polar_num complex_to_polar(complex_num);

complex_num complex_complex_mult(complex_num,complex_num);

complex_num complex_conj(complex_num);

complex_num complex_div (complex_num,complex_num);

#ifdef GENERAL
void welcome(void);
int menu(void);
void operation(int);
complex_num usr_input(void);

#endif






#endif