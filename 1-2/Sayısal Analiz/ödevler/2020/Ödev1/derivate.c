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
  int i;
  float deltaX, x, fd, bd, cd, *fn = get_fn();

  printf("deltaX : ");
  scanf("%f", &deltaX);
  printf("x : ");
  scanf("%f", &x);

  // forward derivation
  fd = (f(x + deltaX, fn) - f(x, fn)) / deltaX;
  printf("Forward Derivation : %f\n", fd);

  // backward derivation
  bd = (f(x, fn) - f(x - deltaX, fn)) / deltaX;
  printf("Backward Derivation : %f\n", bd);

  // central derivation
  cd = (fd + bd) / 2;
  printf("Central Derivation : %f", cd);


  return 0;
}
