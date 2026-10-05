#include <stdio.h>

#define MAX_PLANES 100

int main() {
    int totalPlanes, i, interval;
    int planeIDs[MAX_PLANES], planeDepartureTimes[MAX_PLANES];
    int runway1Planes[MAX_PLANES], runway1Times[MAX_PLANES], runway1Delays[MAX_PLANES];
    int runway2Planes[MAX_PLANES], runway2Times[MAX_PLANES], runway2Delays[MAX_PLANES];
    int runway1Count = 0, runway2Count = 0;
    int runway1TotalDelay = 0, runway2TotalDelay = 0;

    // Input total number of planes
    printf("How many planes are there? : \n");
    scanf("%d", &totalPlanes);

    // Input plane IDs and their scheduled departure times
    printf("Enter the IDs and scheduled departure times of the planes:\n");
    for (i = 0; i < totalPlanes; i++) {
        printf("Enter ID for Plane %d: ", i + 1);
        scanf("%d", &planeIDs[i]);
        printf("Enter scheduled departure time for Plane %d: ", i + 1);
        scanf("%d", &planeDepartureTimes[i]);
    }

    // Input the minimum time interval between two departures on the same runway
    printf("What is the minimum time interval (in minutes) between plane departures? : \n");
    scanf("%d", &interval);

    // Assign the first plane to Runway 1
    runway1Times[0] = planeDepartureTimes[0];
    runway1Planes[0] = planeIDs[0];
    runway1Delays[0] = 0; // No delay for the first plane
    runway1Count++;

    // Assign the second plane to Runway 2
    runway2Times[0] = planeDepartureTimes[1];
    runway2Planes[0] = planeIDs[1];
    runway2Delays[0] = 0; // No delay for the first plane
    runway2Count++;

    // Assign remaining planes to runways
    for (i = 2; i < totalPlanes; i++) {
        if (runway1Times[runway1Count - 1] + interval <= planeDepartureTimes[i]) {
            // Plane can take off on Runway 1 without delay
            runway1Times[runway1Count] = planeDepartureTimes[i];
            runway1Planes[runway1Count] = planeIDs[i];
            runway1Delays[runway1Count] = 0;
            runway1Count++;
        } else if (runway2Times[runway2Count - 1] + interval <= planeDepartureTimes[i]) {
            // Plane can take off on Runway 2 without delay
            runway2Times[runway2Count] = planeDepartureTimes[i];
            runway2Planes[runway2Count] = planeIDs[i];
            runway2Delays[runway2Count] = 0;
            runway2Count++;
        } else {
            // Delay is needed; assign to the runway that becomes available sooner
            if (runway1Times[runway1Count - 1] <= runway2Times[runway2Count - 1]) {
                runway1Times[runway1Count] = runway1Times[runway1Count - 1] + interval;
                runway1Planes[runway1Count] = planeIDs[i];
                runway1Delays[runway1Count] = runway1Times[runway1Count] - planeDepartureTimes[i];
                runway1Count++;
            } else {
                runway2Times[runway2Count] = runway2Times[runway2Count - 1] + interval;
                runway2Planes[runway2Count] = planeIDs[i];
                runway2Delays[runway2Count] = runway2Times[runway2Count] - planeDepartureTimes[i];
                runway2Count++;
            }
        }
    }

    // Print Runway 1 schedule and delay summary
    printf("\nRunway 1 plane schedule:\n");
    for (i = 0; i < runway1Count; i++) {
        printf("Plane ID: %d, Departure Time: %d, Delay: %d\n", 
               runway1Planes[i], runway1Times[i], runway1Delays[i]);
        runway1TotalDelay += runway1Delays[i];
    }
    printf("Average delay for Runway 1: %.2f minutes\n", 
           (float)runway1TotalDelay / runway1Count);

    // Print Runway 2 schedule and delay summary
    printf("\nRunway 2 plane schedule:\n");
    for (i = 0; i < runway2Count; i++) {
        printf("Plane ID: %d, Departure Time: %d, Delay: %d\n", 
               runway2Planes[i], runway2Times[i], runway2Delays[i]);
        runway2TotalDelay += runway2Delays[i];
    }
    printf("Average delay for Runway 2: %.2f minutes\n", 
           (float)runway2TotalDelay / runway2Count);

    return 0;
}