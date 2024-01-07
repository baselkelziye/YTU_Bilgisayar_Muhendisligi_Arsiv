#include <stdio.h>
/* cd /Users/.../hafta2_codes
cc -o test hafta2_enum.c 
*/

int main() {

  enum {Mon, Tue, Wed, Thu, Fri, Sat, Sun} enum_type1;
  // yani Mon=0, Tue=1, .. Sat=5, Sun=6 olur
  enum_type1=Tue;
  printf("enum degeri: %d\n", enum_type1);
  enum_type1=Sat;
  printf("enum degeri: %d\n", enum_type1);

  /* what if i want to assign non-sequential numbers for my enum type? */


  enum {Jan=3, Feb, Mar, Apr=-6, May, Jun=10, Jul} enum_type2;
  enum_type2=Jan;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  enum_type2=Feb;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  enum_type2=Mar;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  enum_type2=Apr;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  enum_type2=May;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  enum_type2=Jun;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  enum_type2=Jul;
  printf("aylar icin enum degeri: %d\n", enum_type2);
  
  return 0;
}
