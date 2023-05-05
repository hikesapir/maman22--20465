#include <stdio.h>
#include <math.h>

typedef struct 
{
    float real;
    float imaginary;
} complex;

void read_comp(complex *temp, float num1, float num2)
{
    temp->real = num1;
    temp->imaginary = num2;
}

void print_comp(complex comp)
{
    char sign = comp.imaginary < 0 ? '-' : '+';
    printf("%f %c (%f)i", comp.real, sign, comp.imaginary);
}

void add_copm(complex comp1, complex comp2)
{
    complex temp;

    temp.real = comp1.real + comp2.real;
    temp.imaginary = comp1.imaginary + comp2.imaginary;

    print_comp(temp);
}

void sub_comp(complex comp1, complex comp2)
{
    complex temp;

    temp.real = comp1.real - comp2.real;
    temp.imaginary = comp1.imaginary - comp2.imaginary;

    print_comp(temp);
}

void mult_comp_real(float num, complex comp)
{
    complex temp;

    temp.real = num * comp.real;
    temp.imaginary = num * comp.imaginary;

    print_comp(temp);
}

void mult_comp_img(float num, complex comp)
{
    complex temp;

    temp.real = num * comp.imaginary * -1;
    temp.imaginary = num * comp.real;

    print_comp(temp);
}

void mult_comp_comp(complex comp1, complex comp2)
{
    complex temp;

    temp.real = (comp1.real * comp2.real) - (comp1.imaginary * comp2.imaginary);
    temp.imaginary = (comp1.real * comp2.real) + (comp1.imaginary * comp2.imaginary);

    print_comp(temp);
}

void abs_comp(complex comp)
{
    double abs_comp;
    abs_comp = pow(comp.real, 2) + pow(comp.imaginary, 2);
    abs_comp = sqrt(abs_comp);

    printf("%lf", abs_comp);
}