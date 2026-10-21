#include <math.h>
#include <stdio.h>

#define SIZE 100
#define E 2.7182818

float denklem_alma();
float denklem_hesap(float);

// method functions
float trapez_y();
float simpson_y();

int derece, cevap;
float denklem_katsayi[SIZE], trigo_katsayi[4], trigo_ic_katsayi[4];
float ln_katsayi, ln_ic_katsayi, e_katsayi, e_uskatsayi;

int main() {

  printf("\nNUMERICAL INTEGRATION");
  printf("\n\nPlease choose the method you want to use:");

  printf("\n\n1) Trapezoidal Method"); // grafik_y
  printf("\n2) Simpson's Method");     // aralik_y

  printf("\n\nMethod: ");
  scanf("%d", &cevap);
  printf("\n-----");

  if (cevap == 1) {
    trapez_y();
  } else if (cevap == 2) {
    simpson_y();
  } else {
    printf("\n\n(!) Invalid selection!");
  }

  return 0;
}

// Functions start here.

float denklem_alma() {

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
    scanf("%f", &denklem_katsayi[i]);
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
    scanf("%f", &trigo_katsayi[0]);
    if (trigo_katsayi[0] != 0) {
      printf("Enter coefficient B: ");
      scanf("%f", &trigo_ic_katsayi[0]);
    }
    printf("-----");
    // cos
    printf("\n(A)cos(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%f", &trigo_katsayi[1]);
    if (trigo_katsayi[1] != 0) {
      printf("Enter coefficient B: ");
      scanf("%f", &trigo_ic_katsayi[1]);
    }
    printf("-----");
    // tan
    printf("\n(A)tan(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%f", &trigo_katsayi[2]);
    if (trigo_katsayi[2] != 0) {
      printf("Enter coefficient B: ");
      scanf("%f", &trigo_ic_katsayi[2]);
    }
    printf("-----");
    // cot
    printf("\n(A)cot(Bx)");
    printf("\nEnter coefficient A: ");
    scanf("%f", &trigo_katsayi[3]);
    if (trigo_katsayi[3] != 0) {
      printf("Enter coefficient B: ");
      scanf("%f", &trigo_ic_katsayi[3]);
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
    scanf("%f", &ln_katsayi);
    printf("Enter coefficient B: ");
    scanf("%f", &ln_ic_katsayi);
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
    scanf("%f", &e_katsayi);
    printf("Enter coefficient B: ");
    scanf("%f", &e_uskatsayi);
  } else {
    e_katsayi = 0;
  }

  // print the equation
  printf("\nYour equation:\n");

  if (denklem_katsayi[derece] != 0) {
    printf("(%.2fx^%d)", denklem_katsayi[derece], derece);
  }
  for (i = derece - 1; i >= 0; i--) {
    if (denklem_katsayi[i] != 0) {
      printf("+(%.2fx^%d)", denklem_katsayi[i], i);
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

float denklem_hesap(float x) {

  int i;
  float sum = 0, x_sum = 1;
  float sinx, cosx, tanx, cotx, lnx, ex;

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
    sum = sum + (denklem_katsayi[i] * x_sum);
    x_sum = x_sum * x;
  }

  // total
  sum = sum + sinx + cosx + tanx + cotx + lnx + ex;
  return sum;
}

// Methods
float trapez_y() {

  int i;
  float alt, ust, n;
  float x0, x1, y0, y1;
  float sum = 0, h;

  printf("\n\nTRAPEZOIDAL METHOD");
  printf("\n\n-----");

  denklem_alma();
  printf("\n\n-----");

  printf("\n\nFor the interval where the integral will be calculated...");
  printf("\nLower value: ");
  scanf("%f", &alt);
  printf("Upper value: ");
  scanf("%f", &ust);

  printf("\nNumber of intervals: ");
  scanf("%f", &n);

  while (n <= 0) {
    printf("\n(!) The number of intervals must be positive.");
    printf("\nPlease enter a valid number of intervals: ");
    scanf("%f", &n);
  }

  h = (ust - alt) / n;
  x1 = alt;

  for (i = 0; i < n; i++) {
    x0 = x1;
    x1 = x1 + h;
    y0 = denklem_hesap(x0);
    y1 = denklem_hesap(x1);
    sum = sum + (y0 + y1);
  }
  sum = (sum * h) / 2;

  printf("\nIntegral value: %f", sum);
}

float simpson_y() {
  int i;
  float alt, ust, n, h;
  float x, y0, yn;
  float sum_cift = 0, sum_tek = 0, sum;

  printf("\n\nSIMPSON'S METHOD");
  printf("\n\n-----");

  denklem_alma();
  printf("\n\n-----");

  printf("\n\nFor the interval where the integral will be calculated...");
  printf("\nLower value: ");
  scanf("%f", &alt);
  printf("Upper value: ");
  scanf("%f", &ust);

  printf("\nNumber of intervals: ");
  scanf("%f", &n);
  i = n;

  while (i % 2 == 1 || i <= 0) {
    printf("\n(!) In this method, the number of intervals must be positive and "
           "even.");
    printf("\nPlease enter a valid number of intervals: ");
    scanf("%f", &n);
    i = n;
  }

  h = (ust - alt) / n;
  y0 = denklem_hesap(alt);
  yn = denklem_hesap(ust);
  x = alt;

  for (i = 1; i < n; i++) {
    x = x + h;
    if (i % 2 == 1) {
      sum_tek = sum_tek + denklem_hesap(x);
    } else {
      sum_cift = sum_cift + denklem_hesap(x);
    }
  }

  sum = ((y0 + yn + (4 * sum_tek) + (2 * sum_cift)) * h) / 3;

  printf("\nIntegral value: %f", sum);
}
