#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "abc:")) != -1)
  // If such an option is followed by a colon (:), the option requires an argument, see c
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case '?': // By default, getopt() prints an error message on standard error, places the erroneous option character in optopt, and returns '?' as the function result.
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt)) 
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        return 1;
      default:
        abort ();
      }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}
/*
./test
./test -a -b
./test -ab
./test -c
./test -c foo
./test -cfoo
./test arg1
./test -a arg1
./test -c foo arg1
./test -a -- -b
./test -a -
./test -a -h
*/