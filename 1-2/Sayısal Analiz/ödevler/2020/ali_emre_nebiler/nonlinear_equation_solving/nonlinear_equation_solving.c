#include <math.h>
#include <stdio.h>

#define SIZE 100
#define E 2.7182818

double denklem_alma();
double turev_alma();
double denklem_hesap(double);
double turev_hesap(double);

// functions required for simple iteration
double denklem_alma_2();
double turev_alma_2();
double turev_hesap_2(double);

// method functions
double grafik_y();
double aralik_y();
double regula_f();
double newton_r();
double basit_i();
double sekant_k();

int derece, cevap;
double denklem_katsayi[2][SIZE], trigo_katsayi[4], trigo_ic_katsayi[4];
double ln_katsayi, ln_ic_katsayi, e_katsayi, e_uskatsayi;

// variables required for simple iteration
int derece_2, turev_derece_2;
double denklem_katsayi_2, turev_katsayi_2;

// denklem_katsayi[0][x] = coefficients of equation terms
// denklem_katsayi[1][x] = coefficients of derivative terms

// trigo_katsayi[x]: coefficients of trigonometric terms
//[  0  ,  1  ,  2  ,  3  ]
//[ sin , cos , tan , cot ]

// trigo_katsayi[x]: coefficients of derivatives of trigonometric terms
//[  0  ,  1   ,  2          ,  3           ]
//[ cos , -sin , 1/(cos*cos) , -1/(sin*sin) ]

int main() {

  printf("\nNONLINEAR EQUATION SOLVING");
  printf("\n\nPlease choose the method you want to use:");

  printf("\n\nCLOSED METHODS:");
  printf("\n1) Graphical Method"); // grafik_y
  printf("\n2) Bisection Method"); // aralik_y
  printf("\n3) Regula Falsi");     // regula_f

  printf("\n\nOPEN METHODS:");
  printf("\n4) Newton-Raphson");   // newton_r
  printf("\n5) Simple Iteration"); // basit_i
  printf("\n6) Secant Method");    // sekant_k

  printf("\n\nMethod: ");
  scanf("%d", &cevap);
  printf("\n-----");

  if (cevap == 1) {
    grafik_y();
  } else if (cevap == 2) {
    aralik_y();
  } else if (cevap == 3) {
    regula_f();
  } else if (cevap == 4) {
    newton_r();
  } else if (cevap == 5) {
    basit_i();
  } else if (cevap == 6) {
    sekant_k();
  } else {
    printf("\n\n(!) Invalid selection!");
  }

  return 0;
}

// Functions start here.

double denklem_alma() {

  int i;

  // polynomial terms
  printf("\n\nEnter the degree of your equation: ");
  scanf("%d", &derece);
  while (derece < 0) {
    printf("\n(!) The degree of your equation cannot be negative.");
    printf("\nPlease enter a valid integer value: ");
    scanf("%d", &derece);
  }
  for (i = 0; i <= derece; i++) {
    printf("Coefficient of x^%d: ", i);
    scanf("%lf", &denklem_katsayi[0][i]);
  }

  // trigonometric terms
  printf("\nAre there trigonometric terms?");
  printf("\n1) Yes   2) No\n");
  scanf("%d", &cevap);

  if (cevap == 1) {
    printf("\nEnter the coefficients of the trigonometric terms.");
    // sin
    printf("\n\n(A)sin(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%lf", &trigo_katsayi[0]);
    if (trigo_katsayi[0] != 0) {
      printf("Enter coefficient B: ");
      scanf("%lf", &trigo_ic_katsayi[0]);
    }
    printf("-----");
    // cos
    printf("\n(A)cos(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%lf", &trigo_katsayi[1]);
    if (trigo_katsayi[1] != 0) {
      printf("Enter coefficient B: ");
      scanf("%lf", &trigo_ic_katsayi[1]);
    }
    printf("-----");
    // tan
    printf("\n(A)tan(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%lf", &trigo_katsayi[2]);
    if (trigo_katsayi[2] != 0) {
      printf("Enter coefficient B: ");
      scanf("%lf", &trigo_ic_katsayi[2]);
    }
    printf("-----");
    // cot
    printf("\n(A)cot(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%lf", &trigo_katsayi[3]);
    if (trigo_katsayi[3] != 0) {
      printf("Enter coefficient B: ");
      scanf("%lf", &trigo_ic_katsayi[3]);
    }
  } else {
    for (i = 0; i < 4; i++) {
      trigo_katsayi[i] = 0;
    }
  }

  // logarithmic term
  printf("\nIs there an lnx term?");
  printf("\n1) Yes   2) No\n");
  scanf("%d", &cevap);

  if (cevap == 1) {
    printf("\n(A)ln(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%lf", &ln_katsayi);
    printf("Enter coefficient B: ");
    scanf("%lf", &ln_ic_katsayi);
  } else {
    ln_katsayi = 0;
    ln_ic_katsayi = 1;
  }

  // exponential term
  printf("\nIs there an e^x term?");
  printf("\n1) Yes   2) No\n");
  scanf("%d", &cevap);

  if (cevap == 1) {
    printf("\n(A)e^((B)x)");
    printf("\nEnter coefficient A: ");
    scanf("%lf", &e_katsayi);
    printf("Enter coefficient B: ");
    scanf("%lf", &e_uskatsayi);
  } else {
    e_katsayi = 0;
  }

  // print the equation
  printf("\nYour equation:\n");

  if (denklem_katsayi[0][derece] != 0) {
    printf("(%.2fx^%d)", denklem_katsayi[0][derece], derece);
  }
  for (i = derece - 1; i >= 0; i--) {
    if (denklem_katsayi[0][i] != 0) {
      printf("+(%.2fx^%d)", denklem_katsayi[0][i], i);
    }
  }
  if (trigo_katsayi[0] != 0) {
    printf("+(%.2fsin(%.2fx))", trigo_katsayi[0], trigo_ic_katsayi[0]);
  }
  if (trigo_katsayi[1] != 0) {
    printf("+(%.2fcos(%.2fx))", trigo_katsayi[1], trigo_ic_katsayi[1]);
  }
  if (trigo_katsayi[2] != 0) {
    printf("+(%.2ftan(%.2fx))", trigo_katsayi[2], trigo_ic_katsayi[2]);
  }
  if (trigo_katsayi[3] != 0) {
    printf("+(%.2fcot(%.2fx))", trigo_katsayi[3], trigo_ic_katsayi[3]);
  }
  if (ln_katsayi != 0) {
    printf("+(%.2fln(%.2fx))", ln_katsayi, ln_ic_katsayi);
  }
  if (e_katsayi != 0) {
    printf("+(%.2fe^(%.2fx))", e_katsayi, e_uskatsayi);
  }
}

double turev_alma() {

  int i;

  for (i = 0; i <= derece - 1; i++) {
    denklem_katsayi[1][i] = (i + 1) * denklem_katsayi[0][i + 1];
  }

  printf("\nDerivative:\n");

  for (i = derece - 1; i > 0; i--) {
    if (denklem_katsayi[1][i] != 0) {
      printf("(%.2fx^%d)+", denklem_katsayi[1][i], i);
    }
  }
  if (denklem_katsayi[1][0] != 0) {
    printf("(%.2f)", denklem_katsayi[1][0]);
  }

  if (trigo_katsayi[0] != 0) {
    printf("+(%.2fcos(%.2fx))", trigo_katsayi[0] * trigo_ic_katsayi[0],
           trigo_ic_katsayi[0]);
  }
  if (trigo_katsayi[1] != 0) {
    printf("+(-%.2fsin(%.2fx))", trigo_katsayi[1] * trigo_ic_katsayi[1],
           trigo_ic_katsayi[1]);
  }
  if (trigo_katsayi[2] != 0) {
    printf("+(%.2f/(cos(%.2fx))^2)", trigo_katsayi[2] * trigo_ic_katsayi[2],
           trigo_ic_katsayi[2]);
  }
  if (trigo_katsayi[3] != 0) {
    printf("+(%.2f/(sin(%.2fx))^2)",
           (-1) * trigo_katsayi[3] * trigo_ic_katsayi[3], trigo_ic_katsayi[3]);
  }

  if (ln_katsayi != 0) {
    printf("+(%.2f/x))", ln_katsayi * ln_ic_katsayi);
  }
  // ln_katsayi*ln_ic_katsayi is also the coefficient of 1/x in the derivative

  if (e_katsayi != 0) {
    printf("+(%.2fe^(%.2fx))", e_katsayi * e_uskatsayi, e_uskatsayi);
  }
}

double denklem_hesap(double x) {

  int i;
  double sum = 0, x_sum = 1;
  double sinx, cosx, tanx, cotx, lnx, ex;

  // trigonometric values
  sinx = trigo_katsayi[0] * sin(trigo_ic_katsayi[0] * x);
  cosx = trigo_katsayi[1] * cos(trigo_ic_katsayi[1] * x);
  if (trigo_katsayi[2] == 0) {
    tanx = 0;
  } else {
    tanx = trigo_katsayi[2] * tan(trigo_ic_katsayi[2] * x);
  }
  if (trigo_katsayi[3] == 0) {
    cotx = 0;
  } else {
    cotx = trigo_katsayi[3] / (tan(trigo_ic_katsayi[3] * x));
  }

  // logarithmic value
  if (ln_katsayi == 0) {
    lnx = 0;
  } else {
    lnx = ln_katsayi * log(ln_ic_katsayi * x);
  }

  // exponential value
  if (e_katsayi == 0) {
    ex = 0;
  } else {
    ex = e_katsayi * pow(E, e_uskatsayi * x);
  }

  // other terms
  for (i = 0; i <= derece; i++) {
    sum = sum + (denklem_katsayi[0][i] * x_sum);
    x_sum = x_sum * x;
  }

  // total
  sum = sum + sinx + cosx + tanx + cotx + lnx + ex;
  return sum;
}

double turev_hesap(double x) {

  int i;
  double sum = 0, x_sum = 1;
  double sinx_t, cosx_t, tanx_t, cotx_t, lnx_t, ex_t;

  // trigonometric values
  sinx_t =
      trigo_ic_katsayi[0] * trigo_katsayi[0] * cos(trigo_ic_katsayi[0] * x);
  cosx_t = (-1) * trigo_ic_katsayi[1] * trigo_katsayi[1] *
           sin(trigo_ic_katsayi[1] * x);
  if (trigo_katsayi[2] == 0) {
    tanx_t = 0;
  } else {
    tanx_t = trigo_ic_katsayi[2] * trigo_katsayi[2] /
             (cos(trigo_ic_katsayi[2] * x) * cos(trigo_ic_katsayi[2] * x));
  }
  if (trigo_katsayi[2] == 0) {
    cotx_t = 0;
  } else {
    cotx_t = (-1) * trigo_ic_katsayi[3] * trigo_katsayi[3] /
             (sin(trigo_ic_katsayi[3] * x) * sin(trigo_ic_katsayi[3] * x));
  }

  // logarithmic values
  if (ln_katsayi == 0) {
    lnx_t = 0;
  } else {
    lnx_t = (ln_katsayi * ln_ic_katsayi) / x;
  }

  // exponential value
  if (e_katsayi == 0) {
    ex_t = 0;
  } else {
    ex_t = e_katsayi * e_uskatsayi * pow(E, e_uskatsayi * x);
  }

  // other terms
  for (i = 0; i <= derece - 1; i++) {
    sum = sum + (denklem_katsayi[1][i] * x_sum);
    x_sum = x_sum * x;
  }

  // total
  sum = sum + sinx_t + cosx_t + tanx_t + cotx_t + lnx_t + ex_t;
  return sum;
}

// functions required for simple iteration
// these functions will be used for g(x)
double denklem_alma_2() {

  printf("\n\nEnter the degree of your equation: ");
  scanf("%d", &derece_2);
  while (derece_2 < 0) {
    printf("\n(!) The degree of your equation cannot be negative.");
    printf("\nPlease enter a valid integer value: ");
    scanf("%d", &derece_2);
  }

  printf("Coefficient of x^%d: ", derece_2);
  scanf("%lf", &denklem_katsayi_2);

  // print the equation
  printf("\nYour equation:\n");
  if (denklem_katsayi_2 != 0) {
    printf("(%.2fx^%d)", denklem_katsayi_2, derece_2);
  }
}

double turev_alma_2() {

  turev_katsayi_2 = derece_2 * denklem_katsayi_2;
  turev_derece_2 = derece_2 - 1;

  printf("\nDerivative:\n");

  printf("(%.2f", turev_katsayi_2);
  if (turev_derece_2 != 0 && turev_katsayi_2 != 0) {
    printf("x^%d", turev_derece_2);
  }
  printf(")");
}

double turev_hesap_2(double x) {

  int i;
  double x_sum = 1;

  for (i = 0; i <= turev_derece_2; i++) {
    x_sum = x_sum * x;
  }

  return turev_katsayi_2 * x_sum;
}

// METHODS

double grafik_y() {

  double x0, delta_x, e;

  printf("\n\nGRAPHICAL METHOD");
  printf("\n\n-----");

  denklem_alma();

  printf("\n\n-----");
  printf("\n\nInitial value of x: ");
  scanf("%lf", &x0);

  printf("Delta x value: ");
  scanf("%lf", &delta_x);

  printf("Epsilon value: ");
  scanf("%lf", &e);

  printf("\n x\t\t f(x)");
  printf("\n---\t\t------");
  printf("\n%f\t%f", x0, denklem_hesap(x0));

  if (denklem_hesap(x0) == 0) {

    printf("\n\nThe equation is satisfied at x = %f.", x0);

  } else if (denklem_hesap(x0) < 0) {

    while (fabs(delta_x) >= e) {
      while (denklem_hesap(x0) < 0) {
        x0 = x0 + delta_x;
        printf("\n%f\t%f", x0, denklem_hesap(x0));
      }
      printf("\n(!) The sign changed.\n(!) Delta was halved.");
      x0 = x0 - delta_x;
      printf("\n%f\t%f", x0, denklem_hesap(x0));
      delta_x = delta_x / 2;
    }
    while (denklem_hesap(x0) < 0) {
      x0 = x0 + delta_x;
      printf("\n%f\t%f", x0, denklem_hesap(x0));
    }

  } else {

    while (fabs(delta_x) >= e) {
      while (denklem_hesap(x0) > 0) {
        x0 = x0 + delta_x;
        printf("\n%f\t%f", x0, denklem_hesap(x0));
      }
      printf("\n(!) The sign changed.\n(!) Delta was halved.");
      x0 = x0 - delta_x;
      printf("\n%f\t%f", x0, denklem_hesap(x0));
      delta_x = delta_x / 2;
    }
    while (denklem_hesap(x0) > 0) {
      x0 = x0 + delta_x;
      printf("\n%f\t%f", x0, denklem_hesap(x0));
    }
  }

  printf("\n(!) The sign changed.\n(!) Delta < Epsilon");
  x0 = x0 - delta_x;
  printf("\n---\t\t------");
  printf("\n%f\t%f", x0, denklem_hesap(x0));

  printf("\n\nThe equation is satisfied at x = %f.", x0);
}

double aralik_y() {

  double alt, ust, orta, e;

  printf("\n\nBISECTION METHOD");
  printf("\n\n-----");

  denklem_alma();

  printf("\n\n-----");

  printf("\n\nLower value: ");
  scanf("%lf", &alt);

  printf("Upper value: ");
  scanf("%lf", &ust);

  if (denklem_hesap(alt) * denklem_hesap(ust) > 0) {
    printf("\n(!) The given interval does not satisfy the required condition.");
    printf("\n(!) f(lower) x f(upper) must be < 0.");
  } else {
    printf("Epsilon value: ");
    scanf("%lf", &e);

    printf("\nalt\t\tf(alt)\t\tust\t\tf(ust)\t\torta\t\tf(orta)");
    printf("\n---\t\t------\t\t---\t\t------\t\t----\t\t-------");

    orta = (alt + ust) / 2;

    while (fabs(denklem_hesap(orta)) >= e) {

      printf("\n%f\t%f", alt, denklem_hesap(alt));
      printf("\t%f\t%f", ust, denklem_hesap(ust));
      printf("\t%f\t%f", orta, denklem_hesap(orta));

      if (denklem_hesap(orta) * denklem_hesap(alt) > 0) {
        alt = orta;
      } else if (denklem_hesap(orta) * denklem_hesap(ust) > 0) {
        ust = orta;
      }
      orta = (alt + ust) / 2;
    }
    printf("\n---\t\t------\t\t---\t\t------\t\t----\t\t-------");
    printf("\n%f\t%f", alt, denklem_hesap(alt));
    printf("\t%f\t%f", ust, denklem_hesap(ust));
    printf("\t%f\t%f < e", orta, denklem_hesap(orta));

    printf("\n\nThe equation is satisfied at x = %f.", orta);
  }
}

double regula_f() {

  double alt, ust, orta, e;

  printf("\n\nREGULA FALSI METHOD");
  printf("\n\n-----");

  denklem_alma();

  printf("\n\n-----");

  printf("\n\nLower value: ");
  scanf("%lf", &alt);

  printf("Upper value: ");
  scanf("%lf", &ust);

  if (denklem_hesap(alt) * denklem_hesap(ust) > 0) {
    printf("\n(!) The given interval does not satisfy the required condition.");
    printf("\n(!) f(lower) x f(upper) must be < 0.");
  } else {
    printf("Epsilon value: ");
    scanf("%lf", &e);

    printf("\nalt\t\tf(alt)\t\tust\t\tf(ust)\t\torta\t\tf(orta)");
    printf("\n---\t\t------\t\t---\t\t------\t\t----\t\t-------");

    orta = (ust * (denklem_hesap(alt)) - alt * (denklem_hesap(ust))) /
           ((denklem_hesap(alt) - denklem_hesap(ust)));

    while (fabs(denklem_hesap(orta)) >= e) {

      printf("\n%f\t%f", alt, denklem_hesap(alt));
      printf("\t%f\t%f", ust, denklem_hesap(ust));
      printf("\t%f\t%f", orta, denklem_hesap(orta));

      if (denklem_hesap(orta) < 0) {
        alt = orta;
      } else if (denklem_hesap(orta) > 0) {
        ust = orta;
      }
      orta = (ust * (denklem_hesap(alt)) - alt * (denklem_hesap(ust))) /
             ((denklem_hesap(alt) - denklem_hesap(ust)));
    }
    printf("\n---\t\t------\t\t---\t\t------\t\t----\t\t-------");
    printf("\n%f\t%f", alt, denklem_hesap(alt));
    printf("\t%f\t%f", ust, denklem_hesap(ust));
    printf("\t%f\t%f < e", orta, denklem_hesap(orta));

    printf("\n\nThe equation is satisfied at x = %f.", orta);
  }
}

double newton_r() {

  double x0, x1, e;

  printf("\n\nNEWTON-RAPHSON METHOD");
  printf("\n\n-----");

  denklem_alma();
  turev_alma();

  printf("\n\n-----");

  printf("\n\nInitial value of x: ");
  scanf("%lf", &x0);

  printf("Epsilon value: ");
  scanf("%lf", &e);

  printf("\nx(k)\t\tx(k+1)\t\t|x(k)-x(k+1)|");
  printf("\n----\t\t------\t\t-------------");

  x1 = x0 - (denklem_hesap(x0) / turev_hesap(x0));

  while (fabs(x1 - x0) >= e) {
    printf("\n%f\t%f\t%f", x0, x1, fabs(x1 - x0));
    x0 = x1;
    x1 = x0 - (denklem_hesap(x0) / turev_hesap(x0));
  }

  printf("\n----\t\t------\t\t-------------");
  printf("\n%f\t%f\t%f < e", x0, x1, fabs(x1 - x0));
  printf("\n\nThe equation is satisfied at x = %f.", x1);
}

double basit_i() {

  double x0, x1, e, us;

  printf("\n\nSIMPLE ITERATION METHOD");
  printf("\n\nEnter the equation f(x) in the form f(x) = g(x) - h(x) = 0.");
  printf("\n(The expression g(x) must be a single term such as x^2 or x^3.)");
  printf("\n\n-----");

  printf("\n\ng(x) function:");
  denklem_alma_2();

  printf("\n\n-----");

  printf("\n\nh(x) function:");
  denklem_alma();

  printf("\n\n-----");
  printf("\n\ng(x) was converted to x.");
  printf("\nx = (h(x)/%.2f)^(1/%d)", denklem_katsayi_2, derece_2);
  printf("\n\n-----");

  printf("\n\nInitial value of x: ");
  scanf("%lf", &x0);

  printf("Epsilon value: ");
  scanf("%lf", &e);

  printf("\n-----");

  printf("\n\ng(x)");
  turev_alma_2();

  printf("\n\nh(x)");
  turev_alma();

  if (fabs(turev_hesap_2(x0)) <= fabs(turev_hesap(x0))) {

    printf("\n\n(!) The convergence condition is not satisfied.");

  } else {

    printf("\n\n(!) The convergence condition is satisfied!");

    us = derece_2;
    x1 = pow(denklem_hesap(x0) / denklem_katsayi_2, 1 / us);

    printf("\n\ng(x)\t\th(x)\t\t|x(k)-x(k+1)|");
    printf("\n----\t\t----\t\t-------------");

    while (fabs(x0 - x1) >= e) {

      printf("\n%f\t%f\t%f", x0, x1, fabs(x0 - x1));
      x0 = x1;
      x1 = pow(denklem_hesap(x0) / denklem_katsayi_2, 1 / us);
    }
    printf("\n----\t\t----\t\t-------------");
    printf("\n%f\t%f\t%f < e", x0, x1, fabs(x0 - x1));
    printf("\n\nThe equation is satisfied at x = %f.", x1);
  }
}

double sekant_k() {

  int i = 2;
  double alt, ust, x0, x1, x_new, e;

  printf("\n\nSECANT METHOD");
  printf("\n\n-----");

  denklem_alma();

  printf("\n\n-----");

  printf("\n\nLower value of x: ");
  scanf("%lf", &alt);

  printf("Upper value of x: ");
  scanf("%lf", &ust);

  printf("Epsilon value: ");
  scanf("%lf", &e);

  x0 = alt, x1 = ust;

  printf("\n\t x\t\t y");
  printf("\n\t---\t\t---");
  printf("\nx0 =\t%f\t%f", x0, denklem_hesap(x0));
  printf("\nx1 =\t%f\t%f", x1, denklem_hesap(x1));
  x_new = x1 - denklem_hesap(x1) *
                   ((x1 - x0) / (denklem_hesap(x1) - denklem_hesap(x0)));

  while (fabs(denklem_hesap(x_new)) >= e) {
    printf("\nx%d =\t%f\t%f", i, x_new, denklem_hesap(x_new));
    x0 = x1;
    x1 = x_new;
    x_new = x1 - denklem_hesap(x1) *
                     ((x1 - x0) / (denklem_hesap(x1) - denklem_hesap(x0)));
    i++;
  }
  i++;
  printf("\n\t---\t\t---");
  printf("\nx%d =\t%f\t%f < e", i, x_new, denklem_hesap(x_new));
  printf("\n\nThe equation is satisfied at x = %f.", x_new);
}
