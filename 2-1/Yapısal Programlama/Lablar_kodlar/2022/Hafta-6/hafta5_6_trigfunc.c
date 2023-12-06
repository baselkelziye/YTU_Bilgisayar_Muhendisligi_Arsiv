/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta5_codes
cc -o test hafta5_6_trigfunc.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // trigonometric functions are here

typedef struct {    double sine, cosine, tangent;
} TRIG; 

/*
TRIG get_trig_vals(double radian_val){
    TRIG result;
    result.sine = sin( radian_val ); 
    result.cosine = cos( radian_val); 
    result.tangent = tan( radian_val ); 
    return result;
}


TRIG * get_trig_vals(double radian_val){
    static TRIG result;
    result.sine = sin( radian_val ); 
    result.cosine = cos( radian_val); 
    result.tangent = tan( radian_val ); 
    return &result;
}
*/

TRIG * get_trig_vals(double radian_val){
    TRIG *result;
    result=(TRIG *)malloc(sizeof(TRIG));
    result->sine = sin( radian_val ); 
    result->cosine = cos( radian_val); 
    result->tangent = tan( radian_val ); 
    return result;
}


int main(){
    double userDefRad;
    //TRIG trigInMain;
    TRIG *trigInMain;

    printf("Enter the radian value to calculate trigonometric function values \n");
    scanf("%lf", &userDefRad);
    trigInMain=get_trig_vals(userDefRad);
    printf("sin(x): %lf\tcos(x): %lf\ttan(x): %lf\n", 
//	trigInMain.sine, trigInMain.cosine, trigInMain.tangent);
	trigInMain->sine, trigInMain->cosine, trigInMain->tangent);

    printf("sin(x): %lf\tcos(x): %lf\ttan(x): %lf\n", 
	sin(userDefRad), cos(userDefRad), tan(userDefRad));

    return 0;
}
