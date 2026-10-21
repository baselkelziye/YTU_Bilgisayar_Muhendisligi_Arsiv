#include <stdio.h>
int main(void) {
    int d[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(d) / sizeof(d[0]);

    for (int i=0;i<size;++i) {
        printf("%d ",d[i]*d[i]);
    }

}
