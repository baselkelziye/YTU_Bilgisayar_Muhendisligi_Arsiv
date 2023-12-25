#include <stdio.h>
#include <math.h>


float f(float x, float *fn)
{
  int i, d = (int)*(fn + 19);
  float result = 0;
  for (i = 0; i <= d; i++)
  {
    result += *(fn + i) * pow(x, d - i);
  }
  return result;
}

float fderivate(float x, float *fn)
{
  int i, d = (int)*(fn + 19);
  float result = 0;
  for (i = 0; i < d; i++)
  {
    result += (d - i) * *(fn + i) * pow(x, d - i - 1);
  }
  return result;
}

float *get_fn()
{
  int i, degree;
  static float fn[20];
  float x, result;

  // get function
  printf("Function degree : ");
  scanf("%d", &degree);
  fn[19] = degree;

  for (i = 0; i <= degree; i++)
  {
    printf("Multiple of %d. degree : ", degree - i);
    scanf("%f", &fn[i]);
  }

  return &fn[0];
}

int main()
{
  int step;
  float xaverage, bottom_limit, top_limit, epsilon, x;
  float *fn = get_fn();

  printf("Bottom Limit : ");
  scanf("%f", &bottom_limit);
  printf("Top Limit : ");
  scanf("%f", &top_limit);
  printf("Epsilon : ");
  scanf("%f", &epsilon);

  if (f(bottom_limit, fn) * f(top_limit, fn) > 0)
  {
    printf("Equation root could not found in [%f,%f]", bottom_limit, top_limit);
  }
  else
  {
    printf("\nCalculating... \n\n");
    step = 0;

    do
    {
      xaverage = (top_limit + bottom_limit) / 2;
      printf("%d. step\n", step);
      printf("bottom limit : %f\n", bottom_limit);
      printf("f(bottom_limit) = %f\n", f(bottom_limit, fn));
      printf("top limit : %f\n", top_limit);
      printf("f(top_limit) = %f\n", f(top_limit, fn));
      printf("xaverage : %f\n", xaverage);
      printf("f(xaverage) : %f\n\n", f(xaverage, fn));

      if (f(bottom_limit, fn) * f(xaverage, fn) < 0)
      {
        top_limit = xaverage;
      }
      else
      {
        bottom_limit = xaverage;
      }
      step++;
    } while (fabs(f(xaverage, fn)) > epsilon && step < 1000); // fabs() fn return absolute value of a float

    if (step < 100)
    {
      printf("Equation solved in %d. step. \nRoot X = %f", step, xaverage);
    }
    else
    {
      printf("Iteration increased more than 1000 times");
    }
  }

  return 0;
}
