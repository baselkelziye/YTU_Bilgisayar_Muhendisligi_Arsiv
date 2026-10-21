#include <math.h>
#include <stdio.h>

#define SIZE 100

float matris_alma();
float determinant(float[SIZE][SIZE], float);

// Methods
float cramer_y();
float yoketme_gauss();
float yoketme_gauss_jordan();
float cholesky_y();
float jacobi_i();
float gauss_seidal();

int cevap;
float N, matris[SIZE][SIZE];
float degisken[SIZE], deger[SIZE];

// degisken[x] = x1, x2 ...
// deger[x] = c1, c2 ...

int main() {
  printf("\nSOLUTION METHODS FOR SYSTEMS OF LINEAR EQUATIONS");
  printf("\n\nDIRECT:");
  printf("\n1) Cramer's Method");
  printf("\n2) Elimination Method");
  printf("\n3) Cholesky Method");

  printf("\n\nITERATIVE:");
  printf("\n4) Jacobi Iteration");
  printf("\n5) Gauss-Seidel");

  printf("\n\nMethod: ");
  scanf("%d", &cevap);
  printf("\n-----");

  if (cevap == 1) {
    cramer_y();
  } else if (cevap == 2) {
    printf("\n\nELIMINATION METHODS:");
    printf("\n1) Gaussian Elimination");
    printf("\n2) Gauss-Jordan Elimination");

    printf("\n\nMethod: ");
    scanf("%d", &cevap);
    printf("\n-----");

    if (cevap == 1) {
      yoketme_gauss();
    } else if (cevap == 2) {
      yoketme_gauss_jordan();
    } else {
      printf("\n\n(!) Invalid selection.");
    }
  } else if (cevap == 3) {
    cholesky_y();
  } else if (cevap == 4) {
    jacobi_i();
  } else if (cevap == 5) {
    gauss_seidal();
  } else {
    printf("\n\n(!) Invalid selection.");
  }

  return 0;
}

// Functions
float matris_alma() {

  int i, j;

  // get the matrix size
  printf("\n\nNumber of equations and variables: ");
  scanf("%f", &N);
  while (N <= 0) {
    printf("\n\n(!) The number of variables must be a positive integer.");
    printf("\nPlease enter a valid value: ");
    scanf("%f", &N);
  }

  // get the matrix values
  printf("\nEnter the equation coefficients.\n");
  for (i = 0; i < N; i++) {
    printf("---\n");
    for (j = 0; j < N; j++) {
      printf("Coefficient of variable %d in equation %d: ", j + 1, i + 1);
      scanf("%f", &matris[i][j]);
    }
    printf("Right-hand-side value of equation %d: ", i + 1);
    scanf("%f", &deger[i]);
  }

  // print the matrix
  printf("\nYour Equation Matrix:");
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%.2f(x%d)\t", matris[i][j], j + 1);
    }
    printf("=  %.2f", deger[i]);
  }
}

float determinant(float a[SIZE][SIZE], float n) {
  int i, j, k, p, r;
  float det = 0;
  float minor[SIZE][SIZE];

  // 1x1
  if (n == 1) {
    return a[0][0];

    // 2x2
  } else if (n == 2) {
    det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
    return det;

    // 3x3, 4x4, ...
  } else {
    for (k = 0; k < n; k++) {
      p = 0;
      r = 0;
      for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (j != k) {
            minor[p][r] = a[i][j];
            r++;
            if (r == n - 1) {
              p++;
              r = 0;
            }
          }
        }
      }
      det = det + a[0][k] * pow(-1, k) * determinant(minor, n - 1);
    }
    return det;
  }
}

// Methods
float cramer_y() {

  int i, j, k;
  float det_matris, temp[SIZE][SIZE];

  printf("\n\nCRAMER'S METHOD");
  printf("\n\n-----");

  matris_alma();

  det_matris = determinant(matris, N);

  printf("\n\nDeterminant of the equation matrix: %.2f", det_matris);
  if (det_matris == 0) {
    printf(
        "\n\n(!) Since the determinant is 0, Cramer's Method cannot be used.");
  } else {
    for (i = 0; i < N; i++) {
      for (k = 0; k < N; k++) {
        for (j = 0; j < N; j++) {
          if (k == i) {
            temp[j][k] = deger[j];
          } else {
            temp[j][k] = matris[j][k];
          }
        }
      }
      degisken[i] = determinant(temp, N) / det_matris;
    }
    // print the variables
    printf("\n\nVariables:");
    for (i = 0; i < N; i++) {
      printf("\nx%d = %f", i + 1, degisken[i]);
    }
  }
}

float yoketme_gauss() {

  int i, j, k;
  float temp1, temp2, sum;

  printf("\n\nGAUSSIAN ELIMINATION");
  printf("\n\n-----");

  matris_alma();

  printf("\n\n-----");

  // create the upper triangular matrix
  for (i = 0; i < N - 1; i++) {
    temp1 = matris[i][i];
    for (j = i + 1; j < N; j++) {
      temp2 = matris[j][i];
      for (k = i; k < N; k++) {
        matris[j][k] = matris[j][k] - ((matris[i][k] / temp1) * temp2);
      }
      deger[j] = deger[j] - ((deger[i] / temp1) * temp2);
    }
  }

  // print the upper triangular matrix
  printf("\n\nYour Upper Triangular Matrix:");
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%.2f(x%d)\t", matris[i][j], j + 1);
    }
    printf("=  %.2f", deger[i]);
  }

  printf("\n\n-----");

  // calculation
  for (i = (N - 1); i >= 0; i--) {
    sum = 0;
    for (j = (N - 1); j >= i; j--) {
      sum = sum + (degisken[j] * matris[i][j]);
    }
    degisken[i] = (deger[i] - sum) / matris[i][i];
  }

  // print the variables
  printf("\n\nVariables:");
  for (i = 0; i < N; i++) {
    printf("\nx%d = %f", i + 1, degisken[i]);
  }
}

float yoketme_gauss_jordan() {

  int i, j, k;
  float temp1, temp2, sum;

  printf("\n\nGAUSS-JORDAN ELIMINATION");
  printf("\n\n-----");

  matris_alma();

  printf("\n\n-----");

  printf("\n\nAfter applying the required operations...");

  // reduce the lower triangular elements to zero
  for (i = 0; i < N - 1; i++) {
    temp1 = matris[i][i];
    for (j = i; j < N; j++) {
      matris[i][j] = matris[i][j] / temp1;
    }
    deger[i] = deger[i] / temp1;
    for (j = i + 1; j < N; j++) {
      temp2 = matris[j][i];
      for (k = i; k < N; k++) {
        matris[j][k] = matris[j][k] - (matris[i][k] * temp2);
      }
      deger[j] = deger[j] - (deger[i] * temp2);
    }
  }
  i = N - 1;
  temp1 = matris[i][i];
  matris[i][i] = 1;
  deger[i] = deger[i] / temp1;

  // print the matrix
  printf("\n\n(!) The lower triangle was reduced to zero.");
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%.2f(x%d)\t", matris[i][j], j + 1);
    }
    printf("=  %.2f", deger[i]);
  }

  // reduce the upper triangular elements to zero
  for (i = N - 1; i > 0; i--) {
    temp1 = matris[i][i];
    for (j = i - 1; j >= 0; j--) {
      temp2 = matris[j][i];
      for (k = i; k > j; k--) {
        matris[j][k] = matris[j][k] - (matris[i][k] * temp2);
      }
      deger[j] = deger[j] - (deger[i] * temp2);
    }
  }

  // print the matrix
  printf("\n\n(!) The upper triangle was reduced to zero.");
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%.2f(x%d)\t", matris[i][j], j + 1);
    }
    printf("=  %.2f", deger[i]);
  }

  printf("\n\n(!) The identity matrix was formed.");

  // print the variables
  printf("\n\nThe variable values are the right-hand-side values of the "
         "equations:");
  for (i = 0; i < N; i++) {
    printf("\nx%d = %f", i + 1, deger[i]);
  }
}

float cholesky_y() {

  int i, j, k;
  float temp1, temp2, sum;
  float L[SIZE][SIZE], U[SIZE][SIZE], Y[SIZE];
  float L_ters[SIZE][SIZE], U_ters[SIZE][SIZE];

  printf("\n\nCHOLESKY METHOD");
  printf("\n\n-----");

  matris_alma();
  printf("\n\n-----");
  printf("\n\n[A] = [U] x [L]");

  // copy the matrix into upper and lower matrices
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      U[i][j] = matris[i][j];
      L[i][j] = matris[i][j];
    }
  }

  // create the lower triangular matrix
  for (i = 0; i < N - 1; i++) {
    temp1 = L[i][i];
    for (j = i + 1; j < N; j++) {
      temp2 = L[i][j];
      for (k = i; k < N; k++) {
        L[k][j] = L[k][j] - ((L[k][i] / temp1) * temp2);
      }
    }
  }

  // print the matrix
  printf("\n\n[L] Lower Triangular Matrix:");
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%.2f(x%d)\t", L[i][j], j + 1);
    }
  }

  // create the upper triangular matrix
  for (i = 0; i < N - 1; i++) {
    temp1 = U[i][i];
    for (j = i; j < N; j++) {
      U[i][j] = U[i][j] / temp1;
    }
    for (j = i + 1; j < N; j++) {
      temp2 = U[j][i];
      for (k = i; k < N; k++) {
        U[j][k] = U[j][k] - (U[i][k] * temp2);
      }
    }
  }
  i = N - 1;
  U[i][i] = 1;

  // print the matrix
  printf("\n\n[U] Upper Triangular Matrix:");
  for (i = 0; i < N; i++) {
    printf("\n");
    for (j = 0; j < N; j++) {
      printf("%.2f(x%d)\t", U[i][j], j + 1);
    }
  }

  printf("\n\n-----");
  printf("\n\n[L] x [Y] = [C]");

  // calculate the Y values
  for (i = 0; i < N; i++) {
    sum = 0;
    for (j = 0; j < i; j++) {
      sum = sum + L[i][j] * Y[j];
    }
    Y[i] = (deger[i] - sum) / L[i][i];
  }

  // print the Y values
  printf("\n\n[Y] Values:");
  for (i = 0; i < N; i++) {
    printf("\ny%d = %f", i + 1, Y[i]);
  }

  printf("\n\n[U] x [X] = [Y]");

  // calculate the variables
  for (i = N - 1; i >= 0; i--) {
    sum = 0;
    for (j = N - 1; j > i; j--) {
      sum = sum + U[i][j] * degisken[j];
    }
    degisken[i] = Y[i] - sum;
  }

  // print the variables
  printf("\n\nVariables:");
  for (i = 0; i < N; i++) {
    printf("\nx%d = %f", i + 1, degisken[i]);
  }
}

float jacobi_i() {

  int i, j, flag = 0, kontrol = 1;
  float temp[SIZE], sum, epsilon;
  // temp[x] initial variable values

  printf("\n\nJACOBI ITERATION");
  printf("\n\n-----");

  matris_alma();
  printf("\n\n-----");

  // check
  while (kontrol == 1) {
    for (i = 0; i < N; i++) {
      sum = 0;
      for (j = 0; j < N; j++) {
        if (j != i) {
          sum = sum + fabs(matris[i][j]);
        }
      }
      if (fabs(matris[i][i]) < sum) {
        kontrol = 0;
        printf("\n\n(!) The convergence check is not satisfied.");
        printf("\nDo you still want to continue?");
        printf("\n1) Yes\t2) Cancel\n");
        scanf("%d", &cevap);
      }
    }
    if (kontrol == 1) {
      printf("\n\n(!) The convergence check is satisfied.");
      kontrol = 0;
      cevap = 1;
    }
  }

  if (cevap == 1) {
    // enter values
    printf("\n\nEnter the initial values of the variables.\n");
    for (i = 0; i < N; i++) {
      printf("x%d: ", i + 1);
      scanf("%f", &temp[i]);
    }
    printf("\nEnter the epsilon value: ");
    scanf("%f", &epsilon);
    printf("\n");

    // print the table
    for (i = 0; i < N; i++) {
      printf("x%d\t\td(x%d)\t\t", i + 1, i + 1);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
      printf("------\t\t------\t\t");
    }
    printf("\n");
    for (i = 0; i < N; i++) {
      printf("%f\t-\t\t", temp[i]);
    }

    // calculate the new x variables
    while (flag == 0) {
      for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
          if (j != i) {
            sum = sum + (matris[i][j] * temp[j]);
          }
        }
        degisken[i] = (deger[i] - sum) / matris[i][i];
      }

      // epsilon check
      kontrol = 1;
      while (kontrol == 1) {
        for (i = 0; i < N; i++) {
          if (fabs(degisken[i] - temp[i]) > epsilon) {
            kontrol = 0;
          }
        }
        if (kontrol == 1) {
          flag = 1;
          kontrol = 0;
        }
      }

      // print
      if (flag != 1) {
        printf("\n");
        for (i = 0; i < N; i++) {
          printf("%f\t%f\t", degisken[i], fabs(degisken[i] - temp[i]));
          temp[i] = degisken[i];
        }
      } else {
        printf("\n");
        for (i = 0; i < N; i++) {
          printf("------\t\t------\t\t");
        }
        printf("\n");
        for (i = 0; i < N; i++) {
          printf("%f\t%f < e\t", degisken[i], fabs(degisken[i] - temp[i]));
        }
        printf("\n\nVariables:");
        for (i = 0; i < N; i++) {
          printf("\nx%d = %f", i + 1, degisken[i]);
        }
      }

    } // end while
  } // end if
}

float gauss_seidal() {

  int i, j, flag = 0, kontrol = 1;
  float temp[SIZE], sum, epsilon;

  printf("\n\nGAUSS-SEIDEL METHOD");
  printf("\n\n-----");

  matris_alma();
  printf("\n\n-----");

  // check
  while (kontrol == 1) {
    for (i = 0; i < N; i++) {
      sum = 0;
      for (j = 0; j < N; j++) {
        if (j != i) {
          sum = sum + fabs(matris[i][j]);
        }
      }
      if (fabs(matris[i][i]) < sum) {
        kontrol = 0;
        printf("\n\n(!) The convergence check is not satisfied.");
        printf("\nDo you still want to continue?");
        printf("\n1) Yes\t2) Cancel\n");
        scanf("%d", &cevap);
      }
    }
    if (kontrol == 1) {
      printf("\n\n(!) The convergence check is satisfied.");
      kontrol = 0;
      cevap = 1;
    }
  }

  if (cevap == 1) {
    // enter values
    printf("\n\nEnter the initial values of the variables.\n");
    for (i = 0; i < N; i++) {
      printf("x%d: ", i + 1);
      scanf("%f", &degisken[i]);
    }
    printf("\nEnter the epsilon value: ");
    scanf("%f", &epsilon);
    printf("\n");

    // print the table
    for (i = 0; i < N; i++) {
      printf("x%d\t\td(x%d)\t\t", i + 1, i + 1);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
      printf("------\t\t------\t\t");
    }
    printf("\n");
    for (i = 0; i < N; i++) {
      printf("%f\t-\t\t", degisken[i]);
    }

    // calculate the new x variables
    while (flag == 0) {
      for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
          if (j != i) {
            sum = sum + (matris[i][j] * degisken[j]);
          }
        }
        degisken[i] = (deger[i] - sum) / matris[i][i];
      }

      // epsilon check
      kontrol = 1;
      while (kontrol == 1) {
        for (i = 0; i < N; i++) {
          if (fabs(degisken[i] - temp[i]) > epsilon) {
            kontrol = 0;
          }
        }
        if (kontrol == 1) {
          flag = 1;
          kontrol = 0;
        }
      }

      // print
      if (flag != 1) {
        printf("\n");
        for (i = 0; i < N; i++) {
          printf("%f\t%f\t", degisken[i], fabs(degisken[i] - temp[i]));
          temp[i] = degisken[i];
        }
      } else {
        printf("\n");
        for (i = 0; i < N; i++) {
          printf("------\t\t------\t\t");
        }
        printf("\n");
        for (i = 0; i < N; i++) {
          printf("%f\t%f < e\t", degisken[i], fabs(degisken[i] - temp[i]));
        }
        printf("\n\nVariables:");
        for (i = 0; i < N; i++) {
          printf("\nx%d = %f", i + 1, degisken[i]);
        }
      }

    } // end while
  } // end if
}
