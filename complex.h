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
  DOUBLE_COMP
};

typedef struct cmd
{
  char *name;
  void (*func)();
  int arg_length;
  int arg_type;
} CMD;

void read_comp(Complex *temp, double num1, double num2);
void print_comp(Complex comp);
void add_comp(Complex comp1, Complex comp2);
void sub_comp(Complex comp1, Complex comp2);
void mult_comp_real(double num, Complex comp);
void mult_comp_img(double num, Complex comp);
void mult_comp_comp(Complex comp1, Complex comp2);
void abs_comp(Complex comp);
