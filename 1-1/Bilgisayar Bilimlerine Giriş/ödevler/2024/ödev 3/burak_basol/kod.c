#include <stdio.h>

// Uncomment the following line to enable test mode
// #define TEST

int main() {
    int i;
    int n, k, temp, delay1 = 0, delay2 = 0, count1 = 0, count2 = 0;

    #ifndef TEST
    printf("Please enter the number of planes (n): ");
    scanf("%d", &n);

    temp = n / 2 + 1;

    if (n < 0) {
        printf("Invalid number of planes\n");
        return 0;
    }
    else if (n == 0) {
        printf("No planes\n");
        return 0;
    }

    printf("Please enter the delay between fligths (k): ");
    scanf("%d", &k);

    if (k < 0) {
        printf("Invalid delay\n");
        return 0;
    }

    if (n % 2 == 0) {
        temp--;
    }

    int planes[n];
    int time[n];
    for (i = 0; i < n; i++) {
        printf("Please enter the number of plane %d: ", i + 1);
        scanf("%d", &planes[i]);
        printf("Please enter the time for plane %d: ", i + 1);
        scanf("%d", &time[i]);
    }
    #endif

    #ifdef TEST

    n = 11;
    k = 2;
    temp = n / 2 + 1;
    int planes[11] = {208,505,123,453,345,761,200,307,201,347,975};
    int time[11]   = {875,875,880,882,882,882,885,885,886,886,886};
    if (n % 2 == 0) {
        temp--;
    }

    #endif

    int airway1[temp];
    int fligth_time1[temp];
    int airway2[temp - 1];
    int fligth_time2[temp - 1];
    
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            airway1[count1] = planes[i];

            if (count1 == 0) {
                fligth_time1[count1] = time[i];
            }
            else if (fligth_time1[count1 - 1] + k > time[i]) {
                fligth_time1[count1] = fligth_time1[count1 - 1] + k;
                delay1 += fligth_time1[count1] - time[i];
            }
            else {
                fligth_time1[count1] = time[i];
            }
            
            count1++;
        }
        else {
            airway2[count2] = planes[i];
            
            if (count2 == 0) {
                fligth_time2[count2] = time[i];
            }
            else if (fligth_time2[count2 - 1] + k > time[i]) {
                fligth_time2[count2] = fligth_time2[count2 - 1] + k;
                delay2 += fligth_time2[count2] - time[i];
            }
            else {
                fligth_time2[count2] = time[i];
            }
            
            count2++;
        }

    }
    
    printf("Airway 1     : ");
    for (i = 0; i < count1; i++) {
        printf("%d ", airway1[i]);
    }
    printf("\n");
    printf("Fligth time 1: ");
    for (i = 0; i < count1; i++) {
        printf("%d ", fligth_time1[i]);
    }
    printf("\n");
    printf("Total delay 1: %f\n\n", (float) delay1 / count1);

    printf("Airway 2     : ");
    for (i = 0; i < count2; i++) {
        printf("%d ", airway2[i]);
    }
    printf("\n");
    printf("Fligth time 2: ");
    for (i = 0; i < count2; i++) {
        printf("%d ", fligth_time2[i]);
    }
    printf("\n");
    printf("Total delay 2: %.2f\n", (float) delay2 / count2);

    printf("Please press Enter to exit...");
    getchar();
    while (getchar() != '\n');
    
    
    return 0;
}
