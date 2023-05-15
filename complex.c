#include <stdio.h>
#include <math.h>
#include "complex.h"

/* Sets a complex variable with a given values
    @param *comp - the complex variable
    @param real - the real part
    @param imaginary - the imaginary parts
 */
void read_comp(Complex *comp, double real, double imaginary)
{
    comp->real = real;
    comp->imaginary = imaginary;
}

/* Prints a complex number, formatted as real+(img)i
   @param comp - the complex number
*/
void print_comp(Complex comp)
{
    char sign = comp.imaginary < 0 ? '-' : '+';
    double img = comp.imaginary < 0 ? comp.imaginary * (-1): comp.imaginary;
    printf("%f %c (%f)i\n", comp.real, sign, img);
}

/* Prints the sum of two complex numbers
   @param comp1 - the complex number
   @param comp2 - the complex number
*/
void add_comp(Complex comp1, Complex comp2)
{
    Complex temp;
    temp.real = comp1.real + comp2.real;
    temp.imaginary = comp1.imaginary + comp2.imaginary;
    print_comp(temp);
}

/* Prints the difference between two complex numbers
   @param comp1 - the complex number
   @param comp2 - the complex number
*/
void sub_comp(Complex comp1, Complex comp2)
{
    Complex temp;
    temp.real = comp1.real - comp2.real;
    temp.imaginary = comp1.imaginary - comp2.imaginary;
    print_comp(temp);
}

/* Prints the product of complex number and real number
   @param comp - the complex number
   @param real - the real number
*/
void mult_comp_real(Complex comp, double real)
{
    Complex temp;
    temp.real = real * comp.real;
    temp.imaginary = real * comp.imaginary;
    print_comp(temp);
}

/* Prints the product of complex number and imaginary number
   @param comp - the complex number
   @param imaginary - the imaginary number
*/
void mult_comp_img(Complex comp, double imaginary)
{
    Complex temp;
    temp.real = imaginary * comp.imaginary * -1;
    temp.imaginary = imaginary * comp.real;
    print_comp(temp);
}

/* Prints the product of two complex numbers
   @param comp1 - the complex number
   @param comp2 - the complex number
*/
void mult_comp_comp(Complex comp1, Complex comp2)
{
    Complex temp;
    temp.real = (comp1.real * comp2.real) - (comp1.imaginary * comp2.imaginary);
    temp.imaginary = (comp1.real * comp2.real) + (comp1.imaginary * comp2.imaginary);
    print_comp(temp);
}

/* Prints the absolute value of a complex number 
   @param comp - the complex number
*/
void abs_comp(Complex comp)
{
    double abs_comp;
    abs_comp = pow(comp.real, 2) + pow(comp.imaginary, 2);
    abs_comp = sqrt(abs_comp);
    printf("%f\n", abs_comp);
}
