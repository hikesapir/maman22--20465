#include <stdio.h>
#include <math.h>
#include "complex.h"

void read_comp(Complex *comp, double num1, double num2)

{

    comp->real = num1;

    comp->imaginary = num2;
}

void print_comp(Complex comp)

{

    char sign = comp.imaginary < 0 ? '-' : '+';

    printf("%f %c (%f)i", comp.real, sign, comp.imaginary);
}

void add_comp(Complex comp1, Complex comp2)

{

    Complex temp;

    temp.real = comp1.real + comp2.real;

    temp.imaginary = comp1.imaginary + comp2.imaginary;

    print_comp(temp);
}

void sub_comp(Complex comp1, Complex comp2)

{

    Complex temp;

    temp.real = comp1.real - comp2.real;

    temp.imaginary = comp1.imaginary - comp2.imaginary;

    print_comp(temp);
}

void mult_comp_real(double num, Complex comp)

{

    Complex temp;

    temp.real = num * comp.real;

    temp.imaginary = num * comp.imaginary;

    print_comp(temp);
}

void mult_comp_img(double num, Complex comp)

{

    Complex temp;

    temp.real = num * comp.imaginary * -1;

    temp.imaginary = num * comp.real;

    print_comp(temp);
}

void mult_comp_comp(Complex comp1, Complex comp2)

{

    Complex temp;

    temp.real = (comp1.real * comp2.real) - (comp1.imaginary * comp2.imaginary);

    temp.imaginary = (comp1.real * comp2.real) + (comp1.imaginary * comp2.imaginary);

    print_comp(temp);
}

void abs_comp(Complex comp)
{
    double abs_comp;
    abs_comp = pow(comp.real, 2) + pow(comp.imaginary, 2);
    abs_comp = sqrt(abs_comp);

    print_comp(comp);
}
