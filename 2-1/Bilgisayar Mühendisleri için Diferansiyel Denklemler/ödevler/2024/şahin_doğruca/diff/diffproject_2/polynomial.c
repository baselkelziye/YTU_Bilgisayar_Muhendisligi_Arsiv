#include <stdio.h>
#include <stdlib.h>

struct term {
    double coeff;
    union type {

    }
    union value {
        double val;
        struct term * ins;
    }

}
