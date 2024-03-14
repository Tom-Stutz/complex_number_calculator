/*******************************************************************************************
AUTHOR   : Tom Stutz
PROGRAM  : Complex_Number_Calculator
FILE NAME: complex.h
NOTES    : Header file for functions related to project
LAST EDIT: THURSDAY MAR 15, 2024, 19:10
VERSION: 1.0.0
*******************************************************************************************/


#ifndef __COMPLEX_H__
#define __COMPLEX_H__

//////////////////////////////////////////////////////////////////////////////////////
//Development definitions N.B., should only choose one to use at a time
//////////////////////////////////////////////////////////////////////////////////////

/* #define TESTING */
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