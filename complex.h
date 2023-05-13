typedef struct
{
  double real;
  double imaginary;
} Complex;

enum argType
{
  COMP_DOUBLE_DOUBLE,
  COMP,
  COMP_COMP,
  COMP_DOUBLE,
  NONE
};

typedef struct cmd
{
  char *name;
  void (*func)();
  int arg_length;
  int arg_type;
} CMD;

/* Sets a complex variable with a given values
    @param *comp - the complex variable
    @param real - the real part
    @param imaginary - the imaginary parts
 */
void read_comp(Complex *comp, double real, double imaginary);

/* Prints a complex number, formatted as real+(img)i
   @param comp - the complex number
*/
void print_comp(Complex comp);

/* Prints the sum of two complex numbers
   @param comp1 - the complex number
   @param comp2 - the complex number
*/
void add_comp(Complex comp1, Complex comp2);

/* Prints the difference between two complex numbers
   @param comp1 - the complex number
   @param comp2 - the complex number
*/
void sub_comp(Complex comp1, Complex comp2);

/* Prints the product of complex number and real number
   @param comp - the complex number
   @param real - the real number
*/
void mult_comp_real(Complex comp, double real);

/* Prints the product of complex number and imaginary number
   @param comp - the complex number
   @param imaginary - the imaginary number
*/
void mult_comp_img(Complex comp, double imaginary);

/* Prints the product of two complex numbers
   @param comp1 - the complex number
   @param comp2 - the complex number
*/
void mult_comp_comp(Complex comp1, Complex comp2);

/* Prints the absolute value of a complex number
   @param comp - the complex number
*/
void abs_comp(Complex comp);