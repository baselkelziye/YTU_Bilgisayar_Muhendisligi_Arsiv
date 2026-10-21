#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    double r;
    Point point;
} Circle;

int isInCircle(Circle circle, Point point) {
    return (pow(point.x - circle.point.x, 2) + pow(point.y - circle.point.y, 2)) <= pow(circle.r, 2);
}

int main() {
    int len;

    printf("kac tane nokta girmek istersiniz : ");
    scanf("%d", &len);

    int i;
    Point * points = (Point *) malloc(sizeof(Point) * len);    

    for(i = 0; i< len; i++) {
        printf("x ve y noktalarini sirasi ile giriniz : ");
        scanf("%lf %lf", &(points[i].x), &(points[i].y));
    }


    Circle * circle = (Circle *) malloc(sizeof(Circle));

    printf("merkezin x, y ve r degerlerini sirasi ile giriniz : ");
    scanf("%lf %lf %lf", &(circle->point.x), &(circle->point.y), &(circle->r));


    for(i = 0; i < len; i++) {
        if(isInCircle(*circle, points[i]) > 0) {
            printf("%lf %lf noktalari cemberin icinde\n", points[i].x, points[i].y);
        } else {
            printf("%lf %lf noktalari cemberin icinde degil\n", points[i].x, points[i].y);
        }
    }

    return 0;
}